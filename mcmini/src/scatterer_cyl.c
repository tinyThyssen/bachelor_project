// scatterer_cyl.c
#include "scatterer_cyl.h"
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
    double n = pack / (Vc_A3 * 1e-30);  // number density in 1/m^3
    double sigma = sigma_barn * 1e-28;    // cross section in m^2
    return n * sigma;                     // macroscopic cross section in 1/m
}

static double sample_free_flight(RNG *rng, double Sigma_t) // total macroscopic cross section in 1/m
{
    double u = rng_uniform01(rng); // random number in [0,1)
    if (u < 1e-15) u = 1e-15; // simple safeguard against log(0)
    return -log(u) / Sigma_t; // free path length sampled from exponential distribution
}

static Vec3 sample_isotropic_dir(RNG *rng) // returns a random unit vector sampled isotropically over the sphere
{
    double u = rng_uniform01(rng);
    double v = rng_uniform01(rng);

    double cosT = 2.0*u - 1.0;
    double sinT = sqrt(fmax(0.0, 1.0 - cosT*cosT));
    double phi  = 2.0*M_PI*v;

    return vec3(sinT*cos(phi), cosT, sinT*sin(phi));
}


static int ray_cyl_intersect(
    Vec3 r0, Vec3 dir, Vec3 center, double radius, double height,
    double *t_entry, double *t_exit)
{
    const double eps = 1e-12;
    Vec3 oc = v_sub(r0, center);

    // Interval from radial condition x^2+z^2 <= R^2 for infinite cylinder.
    double a = dir.x*dir.x + dir.z*dir.z; // a = vx^2 + vz^2. dir ≈ 1. keep for generality
    double b = 2.0*(oc.x*dir.x + oc.z*dir.z); // 
    double c = oc.x*oc.x + oc.z*oc.z - radius*radius; // c = x^2 + z^2 - R^2. oc . oc = |oc|^2 = x^2 + y^2 + z^2, but we only want x^2 + z^2

    double t_side_min = -INFINITY;
    double t_side_max =  INFINITY;

    if (fabs(a) < eps) {
        // Ray parallel to cylinder axis: either always inside side wall or never enters.
        if (c > 0.0) return 0;
    } else {
        double disc = b*b - 4.0*a*c;
        if (disc < 0.0) return 0;
        double sdisc = sqrt(disc);
        double t1 = (-b - sdisc) / (2.0*a);
        double t2 = (-b + sdisc) / (2.0*a);
        if (t1 > t2) {
            double tmp = t1;
            t1 = t2;
            t2 = tmp;
        }
        t_side_min = t1;
        t_side_max = t2;
    }

    // Interval from y slab condition ymin <= y <= ymax.
    double ymin = center.y - 0.5*height;
    double ymax = center.y + 0.5*height;
    double t_y_min = -INFINITY;
    double t_y_max =  INFINITY;

    if (fabs(dir.y) < eps) {
        if (r0.y < ymin || r0.y > ymax) return 0;
    } else {
        double ty1 = (ymin - r0.y) / dir.y;
        double ty2 = (ymax - r0.y) / dir.y;
        if (ty1 > ty2) {
            double tmp = ty1;
            ty1 = ty2;
            ty2 = tmp;
        }
        t_y_min = ty1;
        t_y_max = ty2;
    }

    // Intersect both intervals.
    double tin = fmax(t_side_min, t_y_min);
    double tout = fmin(t_side_max, t_y_max);

    if (tout <= 0.0) return 0;
    if (tout <= tin) return 0;

    *t_entry = tin;
    *t_exit = tout;
    return 1;
}


void scatterer_cyl_init(ScattererCyl *s)
{
    s->center = vec3(0.0, 0.0, 0.0);
    s->radius = 0.01; // m. standard CAMEA analyzer radius is 0.01 m
    s->height = 0.06; // m. standard CAMEA analyzer height is 0.06 m

    s->sigma_abs = 5.08; // barn at 2200 m/s (vanadium)
    s->sigma_inc = 5.08; // barn (vanadium is mostly incoherent scatterer)
    s->VcA3 = 13.827; // Å^3 (vanadium unit cell volume)
    s->pack = 0.6; // typical packing factor for powder sample

    s->enable_absorption = 1;
    s->enable_scattering = 1;
    s->max_scat = 1000; // default max scatters to prevent infinite
}

ScattererEvent scatterer_cyl_interact(const ScattererCyl *s, Particle *p, RNG *rng)
{
    if (!p->alive) return CYLINDER_ABSORB;

    p->vec = v_normalize(p->vec);

    double t_entry, t_exit;
    int hit = ray_cyl_intersect(p->r, p->vec, s->center, s->radius, s->height, &t_entry, &t_exit);
    if (!hit) return CYLINDER_NO_HIT;

    if (t_exit <= 0.0) return CYLINDER_NO_HIT;
    if (t_entry < 0.0) t_entry = 0.0;

    double seg_len = t_exit - t_entry;
    if (seg_len <= 0.0) return CYLINDER_NO_HIT;

    if (t_entry > 0.0) {
        p->r = v_add(p->r, v_scale(p->vec, t_entry));
    }

    double Sig_abs  = (s->enable_absorption ? macro_sigma_per_m(s->sigma_abs, s->pack, s->VcA3) : 0.0);
    if (Sig_abs > 0.0 && p->lambda > 0.0) {
        // McStas-like absorption scaling: my_a*(2200/v), v [m/s] = 3956/lambda[Angstrom]
        double v = 3956.0 / p->lambda;
        Sig_abs *= (2200.0 / v);
    }
    double Sig_scat = (s->enable_scattering ? macro_sigma_per_m(s->sigma_inc, s->pack, s->VcA3) : 0.0);
    double Sig_t    = Sig_abs + Sig_scat;

    if (Sig_t <= 0.0) {
        p->r = v_add(p->r, v_scale(p->vec, seg_len));
        return CYLINDER_TRANSMIT;
    }

    double s_free = sample_free_flight(rng, Sig_t);
    if (s_free >= seg_len) {
        p->r = v_add(p->r, v_scale(p->vec, seg_len));
        return CYLINDER_TRANSMIT;
    }

    p->r = v_add(p->r, v_scale(p->vec, s_free));

    double p_scat = Sig_scat / Sig_t;
    double u = rng_uniform01(rng);

    if (u > p_scat) {
        p->alive = 0;
        return CYLINDER_ABSORB;
    }

    p->vec = sample_isotropic_dir(rng);
    return CYLINDER_SCATTER;
}
