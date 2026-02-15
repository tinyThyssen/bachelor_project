#include "source_div.h"
#include "vec3.h"
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Box-Muller standard normal N(0,1)
static double rng_normal01(RNG *rng) {
    double u1 = rng_uniform01(rng);
    double u2 = rng_uniform01(rng);
    // guard against log(0)
    if (u1 < 1e-12) u1 = 1e-12;
    return sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);
}

Particle source_div_emit(const SourceDiv *src, RNG *rng)
{
    // position sampling: uniform in rectangle
    double u1 = rng_uniform01(rng);
    double u2 = rng_uniform01(rng);

    double x = src->center.x + (u1 - 0.5) * src->xwidth;
    double y = src->center.y + (u2 - 0.5) * src->yheight;
    double z = src->center.z;

    Vec3 pos = vec3(x, y, z);

    // angle sampling: convert focus width from degrees to radians
    double aw_rad = (src->focus_aw * M_PI / 180.0);
    double ah_rad = (src->focus_ah * M_PI / 180.0);

    double theta_x, theta_y;

    if (src->gauss) {
        // Convert FWHM -> sigma
        const double fwhm_to_sigma = 1.0 / (2.0 * sqrt(2.0 * log(2.0)));
        double sig_x = aw_rad * fwhm_to_sigma;
        double sig_y = ah_rad * fwhm_to_sigma;

        theta_x = sig_x * rng_normal01(rng);
        theta_y = sig_y * rng_normal01(rng);
    } else {
        double u3 = rng_uniform01(rng);
        double u4 = rng_uniform01(rng);

        theta_x = (u3 - 0.5) * aw_rad;
        theta_y = (u4 - 0.5) * ah_rad;
    }

    // Build direction from slopes (small-angle exact form via tan)
    double sx = tan(theta_x);
    double sy = tan(theta_y);

    Vec3 dir = v_normalize(vec3(sx, sy, 1.0));

    // wavelength sampling: uniform in [lambda0-dlambda, lambda0+dlambda]
    double u5 = rng_uniform01(rng);
    double lambda = src->lambda0 + (2.0 * u5 - 1.0) * src->dlambda;

    if (lambda <= 0.0)
        lambda = src->lambda0; // safety

    // assemble particle
    Particle p = particle_make(pos, dir);
    p.lambda = lambda;

    // velocity magnitude for neutron: v[m/s] ≈ 3956 / lambda[Å]
    double speed = 3956.0 / lambda;
    p.v = v_scale(dir, speed);

    return p;
}
