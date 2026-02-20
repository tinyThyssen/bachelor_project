#include "monitor_flat.h"
#include "vec3.h"
#include <math.h>
#include <stdlib.h>

// Ray-plane intersection. Returns 1 if hit, 0 if no hit (parallel or behind).
static int ray_plane_hit(Vec3 r0, Vec3 dir, Vec3 plane_center, Vec3 plane_normal, double *t_hit) {
    double denom = v_dot(dir, plane_normal); // ray direction dot plane normal
    if (fabs(denom) < 1e-12) return 0; // return 0 if ray is parallel to plane
    double t = v_dot(v_sub(plane_center, r0), plane_normal) / denom; // compute intersection t
    if (t < 0.0) return 0; // return 0 if intersection is behind ray origin
    *t_hit = t;
    return 1;
}

static inline int clamp_int(int vel, int low, int high) { // clamp integer to [low, high]
    return (vel < low) ? low : (vel > high) ? high : vel;
}

int monitor_flat_open(MonitorFlat *m, const char *path, Vec3 center, double xwidth, double yheight) {
    // Initialize monitor struct with geometry and defaults
    m->center = center; //
    m->normal = vec3(0.0, 0.0, 1.0);
    m->xwidth = xwidth;
    m->yheight = yheight;

    // Set mode and initialize other fields
    m->mode = MONITOR_FLAT_EVENTS;
    m->nx = m->ny = 0;
    m->I = NULL;
    m->hits_total = 0;
    m->hits_in = 0;
    m->n_history = 0;

    // Open output file for event list
    m->fpt = fopen(path, "w");
    if (!m->fpt) return 0;
    fprintf(m->fpt, "hit_x,hit_y,hit_z,theta,phi,weight,lambda\n");
    return 1;
}

int monitor_flat_open_binned(MonitorFlat *m, const char *path, Vec3 center, // function for binned mode
                             double xwidth, double yheight, int nx, int ny,
                             long long n_history)
{
    // Initialize monitor struct with geometry and defaults
    m->center = center;
    m->normal = vec3(0.0, 0.0, 1.0);
    m->xwidth = xwidth;
    m->yheight = yheight;

    // set mode and initialize other fields
    m->mode = MONITOR_FLAT_BINNED;
    m->nx = nx;
    m->ny = ny;
    m->I = NULL;
    m->hits_total = 0;
    m->hits_in = 0;
    m->n_history = n_history;

    // Compute bin edges for later use
    m->xmin = center.x - xwidth / 2.0;
    m->xmax = center.x + xwidth / 2.0;
    m->ymin = center.y - yheight / 2.0;
    m->ymax = center.y + yheight / 2.0;

    // allocate intensity array and open output file
    size_t n = (size_t)nx * (size_t)ny;
    m->I = (double*)calloc(n, sizeof(double));
    if (!m->I) return 0;

    // open output file and write header
    m->fpt = fopen(path, "w");
    if (!m->fpt) {
        free(m->I);
        m->I = NULL;
        return 0;
    }

    // minimal header so Python can recover limits easily
    fprintf(m->fpt, "# binned flat monitor\n");
    fprintf(m->fpt, "# nx=%d ny=%d\n", nx, ny);
    fprintf(m->fpt, "# xmin=%.12g xmax=%.12g ymin=%.12g ymax=%.12g\n",
            m->xmin, m->xmax, m->ymin, m->ymax);
    fprintf(m->fpt, "# n_history=%lld\n", m->n_history);
    fprintf(m->fpt, "# columns: ix,iy,I\n");
    return 1;
}

int monitor_flat_record(MonitorFlat *m, const Particle *p) { // record one particle hit (works for both modes)
    double t_hit;
    if (!ray_plane_hit(p->r, p->vec, m->center, m->normal, &t_hit)) {
        return 0;
    }
    m->hits_total++;

    Vec3 hit = v_add(p->r, v_scale(p->vec, t_hit));

    // bounds check
    if (fabs(hit.x - m->center.x) > m->xwidth / 2.0) return 0;
    if (fabs(hit.y - m->center.y) > m->yheight / 2.0) return 0;
    m->hits_in++;

    // EVENT LIST mode: write one line per hit
    if (m->mode == MONITOR_FLAT_EVENTS) {
        // angles
        double cz = p->vec.z;
        if (cz > 1.0) cz = 1.0;
        if (cz < -1.0) cz = -1.0;
        double theta = acos(cz);
        double phi   = atan2(p->vec.y, p->vec.x);

        fprintf(m->fpt, "%.6f,%.6f,%.6f,%.6f,%.6f,%.6f,%.6f\n",
                hit.x, hit.y, hit.z, theta, phi, p->p, p->lambda);
        return 1;
    }

    // BINNED mode: accumulate intensity
    double fx = (hit.x - m->xmin) / (m->xmax - m->xmin); // [0,1)
    double fy = (hit.y - m->ymin) / (m->ymax - m->ymin);

    int ix = (int)floor(fx * m->nx);
    int iy = (int)floor(fy * m->ny);
    ix = clamp_int(ix, 0, m->nx - 1);
    iy = clamp_int(iy, 0, m->ny - 1);

    size_t idx = (size_t)iy * (size_t)m->nx + (size_t)ix;
    m->I[idx] += p->p;  // sum of weights
    return 1;
}

void monitor_flat_normalize_per_history(MonitorFlat *m) { // normalize binned intensity by total number of histories (I/N)
    if (m->mode != MONITOR_FLAT_BINNED) return;
    if (m->n_history <= 0) return;

    size_t n = (size_t)m->nx * (size_t)m->ny;
    double invN = 1.0 / (double)m->n_history;
    for (size_t i = 0; i < n; i++) m->I[i] *= invN;
}

void monitor_flat_scale_to_total_I(MonitorFlat *m, double Itarget) { // scale binned intensity so that sum(I) matches Itarget
    if (m->mode != MONITOR_FLAT_BINNED) return;

    size_t n = (size_t)m->nx * (size_t)m->ny;
    double sum = 0.0;
    for (size_t i = 0; i < n; i++) sum += m->I[i];
    if (sum <= 0.0) return;

    double s = Itarget / sum;
    for (size_t i = 0; i < n; i++) m->I[i] *= s;
}

void monitor_flat_close(MonitorFlat *m) {
    if (m->mode == MONITOR_FLAT_BINNED && m->fpt && m->I) {
        // Write binned data
        fprintf(m->fpt, "# hits_total=%lld hits_in=%lld\n", m->hits_total, m->hits_in);
        for (int iy = 0; iy < m->ny; iy++) {
            for (int ix = 0; ix < m->nx; ix++) {
                size_t idx = (size_t)iy * (size_t)m->nx + (size_t)ix;
                fprintf(m->fpt, "%d,%d,%.12g\n", ix, iy, m->I[idx]);
            }
        }
    }

    if (m->fpt) fclose(m->fpt);
    m->fpt = NULL;

    free(m->I);
    m->I = NULL;
}
