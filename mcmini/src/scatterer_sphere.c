// scatterer_sphere.c
#include "scatterer_sphere.h"
#include "rng.h"
#include "vec3.h"

#include <math.h>
#include <stdio.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#ifndef INFINITY
#define INFINITY (1.0/0.0)
#endif


// --- helpers ---
static double macro_sigma_per_m(double sigma_barn, double pack, double Vc_A3)
{
    // n = pack / Vc  with Vc in m^3
    double n = pack / (Vc_A3 * 1e-30);  // 1/m^3
    double sig = sigma_barn * 1e-28;    // m^2
    return n * sig;                     // 1/m
}

static double sample_free_flight(RNG *rng, double Sig_t)
{
    double u = rng_uniform01(rng);
    if (u < 1e-15) u = 1e-15;
    return -log(u) / Sig_t;
}

static Vec3 sample_isotropic_dir(RNG *rng)
{
    double u = rng_uniform01(rng);
    double v = rng_uniform01(rng);

    double cosT = 2.0*u - 1.0;
    double sinT = sqrt(fmax(0.0, 1.0 - cosT*cosT));
    double phi  = 2.0*M_PI*v;

    return vec3(sinT*cos(phi), cosT, sinT*sin(phi));
}





/*
find entry and exit intersection of particle ray with the solid sphere. Returns 1 if hit recorded, 0 if no forward hit.
we can use the excact same logic as the monitor sphere. 
instead keep track of both entry and exit points, and return the length of the segment inside the sphere. 
This is the free path length for interaction sampling.
*/
static int ray_sphere_intersect(Vec3 r0, Vec3 dir, Vec3 C, double R, double *t_entry, double *t_exit) {
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

    // t2 is always the larger root; any forward hit requires t2 > 0
    if (t2 <= 0.0) return 0; // sphere is entirely behind the ray

    // entry is the first point in front of the origin; if we start inside, entry is at 0
    double t_entry_val = (t1 > 0.0) ? t1 : 0.0;
    double t_exit_val  = t2;

    *t_entry = t_entry_val;
    *t_exit = t_exit_val;
    return 1; // hit recorded
}






// ---- multiple scattering ----
int transport_sphere(ScattererSphere *s, Particle *p, RNG *rng)
{
    if (!p->alive) return 0;

    // Ensure direction unit
    p->vec = v_normalize(p->vec);

    double Sig_abs  = (s->enable_absorption ? macro_sigma_per_m(s->sigma_abs, s->pack, s->VcA3) : 0.0);
    double Sig_scat = (s->enable_scattering ? macro_sigma_per_m(s->sigma_inc, s->pack, s->VcA3) : 0.0);
    double Sig_t    = Sig_abs + Sig_scat;
    if (Sig_t <= 0.0) return 0;

    int nscat = 0;
    int max_s = (s->max_scat > 0 ? s->max_scat : 1000);

    while (p->alive && nscat < max_s) {

        double tin, tout;
        int hit = ray_sphere_intersect(p->r, p->vec, s->center, s->radius, &tin, &tout);
        if (!hit) return nscat;              // no intersection at all

        if (tout <= 0.0) return nscat;       // sphere is behind particle
        if (tin < 0.0) tin = 0.0;            // if already inside, entry is now

        double L = tout - tin;
        if (L <= 0.0) return nscat;

        // Move to entry point if we were outside
        if (tin > 0.0) {
            p->r = v_add(p->r, v_scale(p->vec, tin));
            // Optional time update: p->t += tin / speed;
        }

        // Sample distance to next interaction along chord
        double sfree = sample_free_flight(rng, Sig_t);

        if (sfree >= L) {
            // No interaction inside: exit sphere
            p->r = v_add(p->r, v_scale(p->vec, L));
            // Optional: p->t += L / speed;
            return nscat;
        }

        // Interaction point inside
        p->r = v_add(p->r, v_scale(p->vec, sfree));
        // Optional: p->t += sfree / speed;

        // Decide scatter vs absorption
        double u = rng_uniform01(rng);
        double p_scat = (Sig_scat / Sig_t);

        if (u > p_scat) {
            // Absorbed
            p->alive = 0;
            return nscat;
        }

        // Scatter: new direction (isotropic for now)
        p->vec = sample_isotropic_dir(rng);
        nscat++;
    }

    return nscat;
}


void scatterer_sphere_init(ScattererSphere *s)
{
    s->center = vec3(0.0, 0.0, 0.0);
    s->radius = 0.1; // m

    s->sigma_abs = 0.4; // barn at 2200 m/s
    s->sigma_inc = 5.0; // barn
    s->VcA3 = 10.0; // Angstrom^3
    s->pack = 0.6; // packing factor [0..1]

    s->enable_absorption = 1;
    s->enable_scattering = 1;
    s->max_scat = 16;
}

ScattererEvent scatterer_sphere_interact(const ScattererSphere *s, Particle *p, RNG *rng)
{
    if (!p->alive) return SPHERE_ABSORB;

    p->vec = v_normalize(p->vec);

    double t_entry, t_exit;
    int hit = ray_sphere_intersect(p->r, p->vec, s->center, s->radius, &t_entry, &t_exit);
    if (!hit) return SPHERE_NO_HIT;

    if (t_exit <= 0.0) return SPHERE_NO_HIT;
    if (t_entry < 0.0) t_entry = 0.0;

    double seg_len = t_exit - t_entry;
    if (seg_len <= 0.0) return SPHERE_NO_HIT;

    if (t_entry > 0.0) {
        p->r = v_add(p->r, v_scale(p->vec, t_entry));
    }

    double Sig_abs  = (s->enable_absorption ? macro_sigma_per_m(s->sigma_abs, s->pack, s->VcA3) : 0.0);
    double Sig_scat = (s->enable_scattering ? macro_sigma_per_m(s->sigma_inc, s->pack, s->VcA3) : 0.0);
    double Sig_t    = Sig_abs + Sig_scat;

    if (Sig_t <= 0.0) {
        p->r = v_add(p->r, v_scale(p->vec, seg_len));
        return SPHERE_TRANSMIT;
    }

    double s_free = sample_free_flight(rng, Sig_t);
    if (s_free >= seg_len) {
        p->r = v_add(p->r, v_scale(p->vec, seg_len));
        return SPHERE_TRANSMIT;
    }

    p->r = v_add(p->r, v_scale(p->vec, s_free));

    double p_scat = Sig_scat / Sig_t;
    double u = rng_uniform01(rng);

    if (u > p_scat) {
        p->alive = 0;
        return SPHERE_ABSORB;
    }

    p->vec = sample_isotropic_dir(rng);
    return SPHERE_SCATTER;
}






// // Initialize scatterer struct with default parameters (vanadium-like)
// void scatterer_sphere_init(ScattererSphere *s) {
//     s->center = vec3(0.0, 0.0, 0.0);
//     s->radius = 0.1; // m

//     s->sigma_abs = 0.4; // barn at 2200 m/s
//     s->sigma_inc = 5.0; // barn
//     s->VcA3 = 10.0; // Å^3
//     s->pack = 0.6; // packing factor [0..1]

//     // s->p_interact = 1.0; // probability to force interaction (variance reduction), typical 1.0
//     // s->order = 1; // 1 => single scattering only (recommended for "simple")
//     s->enable_absorption = 1; // enable absorption
//     s->enable_scattering = 1; // enable scattering
// }

// // Interact a particle with the sphere.
// // - Computes intersection with hollow sphere geometry
// // - Samples free path + decides scatter vs absorption vs transmit
// // - Updates particle in-place (position, direction, weight, alive, etc.)
// // - Returns event type
// ScattererEvent scatterer_sphere_interact(const ScattererSphere *s, Particle *p, RNG *rng) {
//     double t_entry, t_exit;
//     int hit = ray_sphere_intersect(p->r, p->vec, s->center, s->radius, &t_entry, &t_exit);
//     if (!hit) return SCATTERER_NO_HIT;

//     double seg_len = t_exit - t_entry; // length of path inside sphere
//     if (seg_len <= 0.0) return SCATTERER_NO_HIT; // should not happen, but guard against numerical issues

//     // compute interaction probabilities based on material properties and segment length
//     double sigma_inc = s->sigma_inc; // barn
//     double sigma_abs = s->sigma_abs; // barn
//     double Vc = s->VcA3; // Å^3
//     double pack = s->pack; // packing factor [0..1]
//     double v = 3956 / p->lambda; // m/s, neutron velocity from wavelength (lambda in Angstrom)
//     double mu_s = macro_sigma_per_m(sigma_inc, pack, Vc); // 1/m
//     double mu_a_2200 = macro_sigma_per_m(sigma_abs, pack, Vc); // 1/m at 2200 m/s
//     double mu_a = mu_a_2200 * (2200.0 / v);
//     double mu_t = mu_s + mu_a;
//     double p_s = mu_s / mu_t; // probability of scattering vs absorption
//     double p_a = mu_a / mu_t;

//     // sample interaction type
//     double xi = rng_uniform(rng); // random number in [0,1)
//     if (xi < p_a) {
//         // absorption
//         if (s->enable_absorption) {
//             p->alive = 0; // kill particle
//             return SCATTERER_ABSORB;
//         } else {
//             return SCATTERER_TRANSMIT; // treat as transmitted if absorption disabled
//         }
//     } else {
//         // scattering
//         if (s->enable_scattering) {
//             // sample new direction isotropically
//             double phi = 2.0 * M_PI * rng_uniform(rng); // azimuthal angle
//             double costheta = 2.0 * rng_uniform(rng) - 1.0; // cos(theta) uniformly in [-1,1]
//             double sintheta = sqrt(1.0 - costheta*costheta);
//             Vec3 new_dir = vec3(sintheta * cos(phi), sintheta * sin(phi), costheta); // new direction
//             p->vec = new_dir; // update particle direction
//             return SCATTERER_SCATTER;
//         } else {
//             return SCATTERER_TRANSMIT; // treat as transmitted if scattering disabled
//         }
//     }
// }







