#include "monitor_cylinder.h"
#include "vec3.h"
#include <stdlib.h>
#include <math.h>

#ifndef RAD2DEG
#define RAD2DEG (180.0/M_PI)
#endif

// Beamstop modeled like McStas Beamstop: disk in a plane normal to +z.
// beamstop_center defines disk center (including z-plane), beamstop_radius its radius.
static int beamstop_blocks_ray(const MonitorCylinder *m, Vec3 r0, Vec3 dir) {
    if (!m->beamstop_enabled || m->beamstop_radius <= 0.0) return 0;

    // Intersect ray with plane z = beamstop_center.z.
    if (fabs(dir.z) < 1e-15) return 0; // parallel to plane
    double t = (m->beamstop_center.z - r0.z) / dir.z;
    if (t <= 0.0) return 0; // behind/neutron moving away

    Vec3 hit = v_add(r0, v_scale(dir, t));
    double dx = hit.x - m->beamstop_center.x;
    double dy = hit.y - m->beamstop_center.y;
    double r2 = dx*dx + dy*dy;
    return (r2 <= m->beamstop_radius * m->beamstop_radius);
}


// find the first side-wall intersection with the finite y-axis cylinder.
// Returns 1 if hit recorded, 0 if no forward hit.
// must solve (x0 + t*vx)^2 + (z0 + t*vz)^2 = R^2 and y_min <= y <= y_max
static int ray_cylinder_first_hit(Vec3 r0, Vec3 dir, Vec3 C, double R,
                                  double y_min, double y_max, double *t_hit) {
    Vec3 oc = v_sub(r0, C); // oc = r0 - C. Vector from cylinder center to ray origin. oc for origin to center

    // quadratic coefficients for ray-cylinder intersection
    double a = dir.x*dir.x + dir.z*dir.z; // cylinder axis is y, so only x-z radius matters
    double b = 2.0 * (oc.x*dir.x + oc.z*dir.z);
    double c = oc.x*oc.x + oc.z*oc.z - R*R;

    if (fabs(a) < 1e-15) return 0; // ray parallel to cylinder axis

    // discriminant: disc = b^2 - 4ac
    double disc = b*b - 4.0*a*c;
    if (disc < 0.0) return 0; // no real roots, no intersection. cutoff at 0 to avoid numerical issues with grazing rays

    // roots of quadratic: t = (-b ± sqrt(disc)) / (2a)
    double sqrt_disc = sqrt(disc);
    double t1 = (-b - sqrt_disc) / (2.0*a);
    double t2 = (-b + sqrt_disc) / (2.0*a);

    if (t1 > t2) {
        double tmp = t1;
        t1 = t2;
        t2 = tmp;
    }

    // choose the smallest positive side-wall hit within the vertical monitor bounds
    double t = 0.0;
    if (t1 > 0.0) {
        double y = r0.y + t1 * dir.y;
        if (y >= y_min && y < y_max) t = t1;
    }
    if (t == 0.0 && t2 > 0.0) {
        double y = r0.y + t2 * dir.y;
        if (y >= y_min && y < y_max) t = t2;
    }
    if (t == 0.0) return 0;

    // record hit
    *t_hit = t; // store hit distance in output parameter
    return 1; // hit recorded
}


// storing the monitor cylinder data in a CSV file.
int monitor_cylinder_open(MonitorCylinder *m, const char *path, Vec3 center,
                          double radius, double yheight) {
    m->center = center; // from monitor cylinder struct set cetner to input center
    m->radius = radius; // from monitor cylinder struct set radius to input radius
    m->yheight = yheight;
    m->y_min = center.y - 0.5 * yheight;
    m->y_max = center.y + 0.5 * yheight;
    m->mode = MONITOR_CYLINDER_EVENTS;
    m->beamstop_enabled = 0;
    m->beamstop_radius = 0.0;
    m->beamstop_center = center;
    m->direction_only = 0;
    m->I = NULL;
    m->sum_w2 = NULL;
    m->fpt = fopen(path, "w"); // open file for writing.
    if (!m->fpt) return 0; // return 0 if file failed to open

    // CSV header: hit point + angles + weight
    fprintf(m->fpt, "hit_x,hit_y,hit_z,phi,phi_deg,weight,lambda\n"); // write header line to file
    return 1; // return 1 if successfull
}


// open binned monitor cylinder. Initializes intensity array and opens output file with header. Returns 1 if success, 0 if failure.
int monitor_cylinder_open_binned(MonitorCylinder *m, const char *path, Vec3 center,
                             double radius, double yheight,
                             int nr, int ny, long long n_history)
{
    m->center = center;
    m->radius = radius;
    m->yheight = yheight;
    m->mode = MONITOR_CYLINDER_BINNED;
    m->beamstop_enabled = 0;
    m->beamstop_radius = 0.0;
    m->beamstop_center = center;
    m->direction_only = 0;
    m->nr = nr;
    m->ny = ny;
    m->n_history = n_history;
    m->I = (double*)calloc((size_t)nr * (size_t)ny, sizeof(double)); // allocate memory for intensity array
    m->sum_w2 = (double*)calloc((size_t)nr * (size_t)ny, sizeof(double));
    if (!m->I || !m->sum_w2) {
        free(m->I);
        free(m->sum_w2);
        m->I = NULL;
        m->sum_w2 = NULL;
        return 0;
    }

    m->hits_total = 0;
    m->hits_in = 0;

    m->fpt = fopen(path, "w"); // open file for writing.
    if (!m->fpt) {
        free(m->I); // free allocated memory if file fails to open
        free(m->sum_w2);
        m->I = NULL;
        m->sum_w2 = NULL;
        return 0; // return 0 if file failed to open
    }

    m->phi_min   = -180.0;
    m->phi_max   =  180.0;   // treat as half-open [-180,180)
    m->y_min = center.y - 0.5 * yheight;
    m->y_max = center.y + 0.5 * yheight;

    fprintf(m->fpt, "# binned cylinder monitor\n");
    fprintf(m->fpt, "# nr=%d ny=%d\n", m->nr, m->ny);
    fprintf(m->fpt, "# radius=%.12g yheight=%.12g\n", m->radius, m->yheight);
    fprintf(m->fpt, "# n_history=%lld\n", m->n_history);
    fprintf(m->fpt, "# columns: ix,iy,I,sigma\n");
    fprintf(m->fpt, "# phi in [%.12g, %.12g] deg\n", m->phi_min, m->phi_max);
    fprintf(m->fpt, "# y in [%.12g, %.12g] m\n", m->y_min, m->y_max);

    return 1; // return 1 if successful
}




// record intersection point of particle ray with the cylinder. Returns 1 if hit recorded, 0 if no forward hit.
int monitor_cylinder_record(MonitorCylinder *m, const Particle *p) {
    if (beamstop_blocks_ray(m, p->r, p->vec)) {
        return 0;
    }

    double t_hit;
    if (!ray_cylinder_first_hit(p->r, p->vec, m->center, m->radius,
                                m->y_min, m->y_max, &t_hit)) { // return 0 if no hit
        return 0;
    }

    // hit point
    Vec3 hit = v_add(p->r, v_scale(p->vec, t_hit)); // hit = r + t_hit * vec. hit point = ray origin + hit distance * ray direction

    // collect events if in event mode, otherwise accumulate in bins if in binned mode. For now we always collect events, but we could add a mode flag to switch between them later.
    if (m->mode == MONITOR_CYLINDER_EVENTS) {
        // direction from center to hit (on cylinder)
        Vec3 u = v_scale(v_sub(hit, m->center), 1.0 / m->radius); // u = (hit - center) / radius. unit vector from center to hit point on cylinder

        double phi = atan2(u.x, u.z);
        double phi_deg = phi * RAD2DEG;


        fprintf(m->fpt, "%.10g,%.10g,%.10g,%.10g,%.10g,%.10g,%.10g\n",
                hit.x, hit.y, hit.z, phi, phi_deg, p->p, p->lambda);
    // else if (m->mode == MONITOR_CYLINDER_BINNED) {
    } else if (m->mode == MONITOR_CYLINDER_BINNED) {

        Vec3 u;
        if (m->direction_only) {
            // Direction-only mode ignores ray origin and bins purely by outgoing direction.
            double dir_norm = sqrt(v_dot(p->vec, p->vec));
            if (dir_norm <= 0.0) return 0;
            u = v_scale(p->vec, 1.0 / dir_norm);
        } else {
            // Geometric mode bins by the actual hit point on the monitor cylinder.
            u = v_scale(v_sub(hit, m->center), 1.0 / m->radius);
        }

        double phi_rad = atan2(u.x, u.z);  // [-pi, pi]
        double phi_deg = phi_rad * RAD2DEG; // [-180, 180]

        // Map to [0,1)
        double fphi = (phi_deg - m->phi_min) / (m->phi_max - m->phi_min);
        double fy    = (hit.y   - m->y_min)   / (m->y_max   - m->y_min);

        // Treat phi as periodic: atan2 can in principle give +180.
        if (fphi >= 1.0 && phi_deg <= m->phi_max + 1e-12) {
            fphi = 0.0;
        }

        // Reject true out-of-range hits instead of clamping into edge bins.
        if (fphi < 0.0 || fphi >= 1.0) return 0;
        if (fy    < 0.0 || fy    >= 1.0) return 0;

        int ix = (int)floor(fphi * m->nr);
        int iy = (int)floor(fy    * m->ny);

        /* Safety guard against possible floating-point edge cases. */
        if (ix < 0 || ix >= m->nr) return 0;
        if (iy < 0 || iy >= m->ny) return 0;
        
        {
            size_t idx = (size_t)iy * (size_t)m->nr + (size_t)ix;
            m->I[idx] += p->p; // accumulate weight in bin
            m->sum_w2[idx] += p->p * p->p; // accumulate squared weights for variance estimate
        }

        m->hits_total++; // increment total hits
        m->hits_in++; // increment hits in bounds
        return 1;
    }
    return 1; // hit recorded
}



void monitor_cylinder_normalize_per_history(MonitorCylinder *m) {
    if (m->mode == MONITOR_CYLINDER_BINNED && m->n_history > 0) {
        size_t n = (size_t)m->nr * (size_t)m->ny;
        double inv_n_history = 1.0 / (double)m->n_history;
        double inv_n_history2 = inv_n_history * inv_n_history;
        for (size_t i = 0; i < n; i++) {
            m->I[i] *= inv_n_history; // I <- I / n_history
            m->sum_w2[i] *= inv_n_history2; // Var(I) <- sum(w^2) / n_history^2
        }
    }
}

void monitor_cylinder_scale_to_total_I(MonitorCylinder *m, double Itarget) {
    if (m->mode == MONITOR_CYLINDER_BINNED) {
        size_t n = (size_t)m->nr * (size_t)m->ny;
        double sum = 0.0;
        for (size_t i = 0; i < n; i++) {
            sum += m->I[i]; // sum(I)
        }
        if (sum > 0.0) {
            double scale = Itarget / sum; // Itarget / sum(I)
            for (size_t i = 0; i < n; i++) {
                m->I[i] *= scale; // I <- I * scale
                m->sum_w2[i] *= scale * scale; // Var(I) scales quadratically
            }
        }
    }
}



// Close the monitor cylinder file 
void monitor_cylinder_close(MonitorCylinder *m) {
    if (m->mode == MONITOR_CYLINDER_BINNED && m->fpt && m->I && m->sum_w2) {
        fprintf(m->fpt, "# hits_total=%lld hits_in=%lld\n", m->hits_total, m->hits_in);
        fprintf(m->fpt, "# columns: ix,iy,I,sigma\n");
        for (int iy = 0; iy < m->ny; iy++) {
            for (int ix = 0; ix < m->nr; ix++) {
                size_t idx = (size_t)iy*(size_t)m->nr + (size_t)ix;
                double sigma = sqrt(m->sum_w2[idx]);
                fprintf(m->fpt, "%d,%d,%.12g,%.12g\n", ix, iy, m->I[idx], sigma);
            }
        }
        free(m->I);
        free(m->sum_w2);
        m->I = NULL;
        m->sum_w2 = NULL;
    }

    if (m->fpt) fclose(m->fpt);
    m->fpt = NULL;
}
