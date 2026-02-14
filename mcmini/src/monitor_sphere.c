#include "monitor_sphere.h"
#include "vec3.h"
#include <math.h>

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
    m->fpt = fopen(path, "w"); // open file for writing.
    if (!m->fpt) return 0; // return 0 if file failed to open

    // CSV header: hit point + angles + weight
    fprintf(m->fpt, "hit_x,hit_y,hit_z,theta,phi,weight,lambda\n"); // write header line to file
    return 1; // return 1 if successfull
}
// Close the monitor sphere file 
void monitor_sphere_close(MonitorSphere *m) {
    if (m->fpt) fclose(m->fpt); // close file if open
    m->fpt = NULL; // set file pointer to NULL
}


// record intersection point of particle ray with the sphere. Returns 1 if hit recorded, 0 if no forward hit.
int monitor_sphere_record(MonitorSphere *m, const Particle *p) {
    double t_hit;
    if (!ray_sphere_first_hit(p->r, p->vec, m->center, m->radius, &t_hit)) { // return 0 if no hit
        return 0;
    }

    // hit point
    Vec3 hit = v_add(p->r, v_scale(p->vec, t_hit)); // hit = r + t_hit * vec. hit point = ray origin + hit distance * ray direction

    // direction from center to hit (on sphere)
    Vec3 u = v_scale(v_sub(hit, m->center), 1.0 / m->radius); // u = (hit - center) / radius. unit vector from center to hit point on sphere

    // spherical angles (physics convention)
    // theta: polar angle from +z, phi: azimuth in x-y plane
    double theta = acos(fmax(-1.0, fmin(1.0, u.z))); // theta = arccos(u.z). polar angle from +z axis. clamp u.z to [-1, 1] to avoid numerical issues
    double phi   = atan2(u.y, u.x); // phi = atan2(u.y, u.x). azimuthal angle in x-y plane from +x axis. atan2 returns value in [-pi, pi]
    if (phi < 0.0) phi += 2.0 * M_PI;

    fprintf(m->fpt, "%.10g,%.10g,%.10g,%.10g,%.10g,%.10g,%.10g\n",
            hit.x, hit.y, hit.z, theta, phi, p->p, p->lambda);

    return 1;
}




