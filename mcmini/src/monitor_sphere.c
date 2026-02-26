#include "monitor_sphere.h"
#include "vec3.h"
#include <stdlib.h>
#include <math.h>

#ifndef RAD2DEG
#define RAD2DEG (180.0/M_PI)
#endif


// find the first intersection of particle ray with the sphere. Returns 1 if hit recorded, 0 if no forward hit.
// must solve |(r0 - C) + t dir|^2 = R^2
static int ray_sphere_first_hit(Vec3 r0, Vec3 dir, Vec3 C, double R, double *t_hit) {
    Vec3 oc = v_sub(r0, C); // oc = r0 - C. Vector from sphere center to ray origin. oc for origin to center

    // quadratic coefficients for ray-sphere intersection
    double a = v_dot(dir, dir); // a = vx^2 + vy^2 + vz^2. dir ≈ 1. keep for generality
    double b = 2 * v_dot(oc, dir); // b = 2 * (x*vx + y*vy + z*vz). 
    double c = v_dot(oc, oc) - R*R; // c = x^2 + y^2 + z^2 - R^2. oc . oc = |oc|^2 = x^2 + y^2 + z^2

    // discriminant: disc = b^2 - 4ac
    double disc = b*b - 4.0*a*c;
    if (disc < 0.0) return 0; // no real roots, no intersection

    // roots of quadratic: t = (-b ± sqrt(disc)) / (2a)
    double sqrt_disc = sqrt(disc);
    double t1 = (-b - sqrt_disc) / (2.0*a);
    double t2 = (-b + sqrt_disc) / (2.0*a);

    // choose the smallest positive t
    double t = 0.0; // initialize t to 0.0
    if (t1 > 0.0) t = t1; // if t1 is positive, use t1
    else if (t2 > 0.0) t = t2; // if t1 is not positive but t2 is, use t2
    else return 0; // if neither t1 nor t2 is positive, no forward hit

    // record hit
    *t_hit = t; // store hit distance in output parameter
    return 1; // hit recorded
}


// storing the monitor sphere data in a CSV file.
int monitor_sphere_open(MonitorSphere *m, const char *path, Vec3 center, double radius) {
    m->center = center; // from monitor sphere struct set cetner to input center
    m->radius = radius; // from monitor sphere struct set radius to input radius
    m->mode = MONITOR_SPHERE_EVENTS;
    m->fpt = fopen(path, "w"); // open file for writing.
    if (!m->fpt) return 0; // return 0 if file failed to open

    // CSV header: hit point + angles + weight
    fprintf(m->fpt, "hit_x,hit_y,hit_z,theta,phi,theta_deg,phi_deg,weight,lambda\n"); // write header line to file
    return 1; // return 1 if successfull
}


// open binned monitor sphere. Initializes intensity array and opens output file with header. Returns 1 if success, 0 if failure.
int monitor_sphere_open_binned(MonitorSphere *m, const char *path, Vec3 center, double radius,
                             int nx, int ny, long long n_history)
{
    m->center = center;
    m->radius = radius;
    m->mode = MONITOR_SPHERE_BINNED;
    m->nx = nx;
    m->ny = ny;
    m->n_history = n_history;
    m->I = (double*)calloc((size_t)nx * (size_t)ny, sizeof(double)); // allocate memory for intensity array
    if (!m->I) return 0; // return 0 if allocation failed

    m->hits_total = 0;
    m->hits_in = 0;

    m->fpt = fopen(path, "w"); // open file for writing.
    if (!m->fpt) {
        free(m->I); // free allocated memory if file fails to open
        m->I = NULL;
        return 0; // return 0 if file failed to open
    }

    m->phi_min   = -180.0;
    m->phi_max   =  180.0;   // treat as half-open [-180,180)
    m->theta_min =  -90.0;
    m->theta_max =   90.0;   // treat as half-open [-90,90)




    fprintf(m->fpt, "# binned sphere monitor\n");
    fprintf(m->fpt, "# nx=%d ny=%d\n", nx, ny);
    fprintf(m->fpt, "# n_history=%lld\n", m->n_history);
    fprintf(m->fpt, "# columns: ix,iy,I\n");
    fprintf(m->fpt, "# phi in [%.12g, %.12g] deg\n", m->phi_min, m->phi_max);
    fprintf(m->fpt, "# theta in [%.12g, %.12g] deg\n", m->theta_min, m->theta_max);

    return 1; // return 1 if successful
}




// record intersection point of particle ray with the sphere. Returns 1 if hit recorded, 0 if no forward hit.
int monitor_sphere_record(MonitorSphere *m, const Particle *p) {
    double t_hit;
    if (!ray_sphere_first_hit(p->r, p->vec, m->center, m->radius, &t_hit)) { // return 0 if no hit
        return 0;
    }

    // hit point
    Vec3 hit = v_add(p->r, v_scale(p->vec, t_hit)); // hit = r + t_hit * vec. hit point = ray origin + hit distance * ray direction

    // collect events if in event mode, otherwise accumulate in bins if in binned mode. For now we always collect events, but we could add a mode flag to switch between them later.
    if (m->mode == MONITOR_SPHERE_EVENTS) {
        // direction from center to hit (on sphere)
        Vec3 u = v_scale(v_sub(hit, m->center), 1.0 / m->radius); // u = (hit - center) / radius. unit vector from center to hit point on sphere

        // spherical angles (physics convention)
        // theta: polar angle from +z, phi: azimuth in x-y plane
        double theta = atan2(u.x, u.z); // theta = arccos(u.z). polar angle from +z axis. clamp u.z to [-1, 1] to avoid numerical issues
        double phi   = atan2(u.y, sqrt(u.x*u.x + u.z*u.z)); // phi = atan2(u.y, u.x). azimuthal angle in x-y plane from +x axis. atan2 returns value in [-pi, pi]

        double phi_deg   = phi * RAD2DEG;
        double theta_deg = theta * RAD2DEG;


        fprintf(m->fpt, "%.10g,%.10g,%.10g,%.10g, %10g, %10g,%.10g,%.10g,%.10g\n",
                hit.x, hit.y, hit.z, theta, phi, theta_deg, phi_deg, p->p, p->lambda);
    // else if (m->mode == MONITOR_SPHERE_BINNED) {
    } else if (m->mode == MONITOR_SPHERE_BINNED) {

        // unit vector from center to hit point on sphere
        Vec3 u = v_scale(v_sub(hit, m->center), 1.0 / m->radius); // direction unit vector from center to hit

        // McStas-like 4PI angular coordinates
        double phi_rad   = atan2(u.x, u.z);  // [-pi, pi]
        double theta_rad = atan2(u.y, sqrt(u.x*u.x + u.z*u.z));   // [-pi/2, pi/2]

        double phi_deg   = phi_rad   * RAD2DEG; // [-180, 180]
        double theta_deg = theta_rad * RAD2DEG; // [-90,  90]

        // Map to [0,1)
        double fphi = (phi_deg   - m->phi_min)   / (m->phi_max   - m->phi_min); // convert phi from [phi_min, phi_max) to [0,1)
        double fth  = (theta_deg - m->theta_min) / (m->theta_max - m->theta_min); // convert theta from [theta_min, theta_max) to [0,1)

        int ix = (int)floor(fphi * m->nx); // convert phi to bin index
        int iy = (int)floor(fth  * m->ny); // convert theta to bin index

        // Clamp edges (handles phi==180 or theta==90)
        if (ix < 0) ix = 0; // clamp ix to [0, nx-1]
        if (ix >= m->nx) ix = m->nx - 1;
        if (iy < 0) iy = 0;
        if (iy >= m->ny) iy = m->ny - 1;

        m->I[(size_t)iy * (size_t)m->nx + (size_t)ix] += p->p; // accumulate weight in bin

        m->hits_total++; // increment total hits
        m->hits_in++; // increment hits in bounds
        return 1;
    }
    return 1; // hit recorded
}



void monitor_sphere_normalize_per_history(MonitorSphere *m) {
    if (m->mode == MONITOR_SPHERE_BINNED && m->n_history > 0) {
        size_t n = (size_t)m->nx * (size_t)m->ny;
        for (size_t i = 0; i < n; i++) {
            m->I[i] /= (double)m->n_history; // I <- I / n_history
        }
    }
}

void monitor_sphere_scale_to_total_I(MonitorSphere *m, double Itarget) {
    if (m->mode == MONITOR_SPHERE_BINNED) {
        size_t n = (size_t)m->nx * (size_t)m->ny;
        double sum = 0.0;
        for (size_t i = 0; i < n; i++) {
            sum += m->I[i]; // sum(I)
        }
        if (sum > 0.0) {
            double scale = Itarget / sum; // Itarget / sum(I)
            for (size_t i = 0; i < n; i++) {
                m->I[i] *= scale; // I <- I * scale
            }
        }
    }
}



// Close the monitor sphere file 
void monitor_sphere_close(MonitorSphere *m) {
    if (m->mode == MONITOR_SPHERE_BINNED && m->fpt && m->I) {
        fprintf(m->fpt, "# hits_total=%lld hits_in=%lld\n", m->hits_total, m->hits_in);
        fprintf(m->fpt, "# columns: ix,iy,I\n");
        for (int iy = 0; iy < m->ny; iy++) {
            for (int ix = 0; ix < m->nx; ix++) {
                size_t idx = (size_t)iy*(size_t)m->nx + (size_t)ix;
                fprintf(m->fpt, "%d,%d,%.12g\n", ix, iy, m->I[idx]);
            }
        }
        free(m->I);
        m->I = NULL;
    }

    if (m->fpt) fclose(m->fpt);
    m->fpt = NULL;
}

