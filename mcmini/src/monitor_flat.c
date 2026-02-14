#include "monitor_flat.h"
#include "vec3.h"
#include <math.h>


// find intersection of beam with flat plane
static int ray_plane_hit(Vec3 r0, Vec3 dir, Vec3 plane_center, Vec3 plane_normal, double *t_hit) {
    double denom = v_dot(dir, plane_normal); // dot product of ray direction and plane normal
    if (fabs(denom) < 1e-12) return 0;  // ray is parallel to plane, no hit

    double t = v_dot(v_sub(plane_center, r0), plane_normal) / denom; // calculate t for intersection point
    if (t < 0.0) return 0; // intersection is behind ray origin, no hit

    *t_hit = t; // store hit distance in output parameter
    return 1; // hit recorded
}

// storing the monitor flat data in a CSV file.
int monitor_flat_open(MonitorFlat *m, const char *path, Vec3 center, double xwidth, double yheight) {
    m->center = center; // from monitor flat struct set center to input center
    m->xwidth = xwidth; // from monitor flat struct set xwidth to input xwidth
    m->yheight = yheight; // from monitor flat struct set yheight to input yheight
    m->fpt = fopen(path, "w"); // open file for writing.
    if (!m->fpt) return 0; // return 0 if file failed to open

    // CSV header: hit point + angles + weight
    fprintf(m->fpt, "hit_x,hit_y,hit_z,theta,phi,weight,lambda\n"); // write header line to file
    return 1; // return 1 if successfull
}
// Close the monitor flat file 
void monitor_flat_close(MonitorFlat *m) {
    if (m->fpt) fclose(m->fpt); // close file if open
    m->fpt = NULL; // set file pointer to NULL
}

// record intersection point of particle ray with the plane. Returns 1 if hit recorded, 0 if no forward hit.
int monitor_flat_record(MonitorFlat *m, const Particle *p) {
    // plane normal is +z direction
    Vec3 plane_normal = {0.0, 0.0, 1.0};


    double t_hit;
    if (!ray_plane_hit(p->r, p->vec, m->center, plane_normal, &t_hit)) { // return 0 if no hit
        return 0;
    }

    // calculate hit point
    Vec3 hit_point = v_add(p->r, v_scale(p->vec, t_hit));

    // check if hit point is within flat monitor bounds
    if (fabs(hit_point.x - m->center.x) > m->xwidth / 2.0) return 0; // outside xwidth bounds
    if (fabs(hit_point.y - m->center.y) > m->yheight / 2.0) return 0; // outside yheight bounds

    // calculate angles
    double cz = p->vec.z;
    if (cz > 1.0) cz = 1.0;
    if (cz < -1.0) cz = -1.0;
    double theta = acos(cz);
    double phi = atan2(p->vec.y, p->vec.x); // azimuthal angle in xy-plane

    // record hit to file
    fprintf(m->fpt, "%.6f,%.6f,%.6f,%.6f,%.6f,%.6f,%.6f\n",
            hit_point.x, hit_point.y, hit_point.z,
            theta, phi,
            p->p,
            p->lambda);

    return 1; // hit recorded
}
