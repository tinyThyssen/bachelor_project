#include "source_4pi.h"
#include "vec3.h"
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


Particle source_4pi_emit(const Source4Pi *src, RNG *rng) {
    Vec3 pos = src->center;

    // Sample an isotropic unit direction over 4*pi steradians.
    double u1 = rng_uniform01(rng);
    double u2 = rng_uniform01(rng);
    double z = 2.0*u1 - 1.0;
    double phi = 2.0 * M_PI * u2;
    double rxy = sqrt(fmax(0.0, 1.0 - z*z));
    Vec3 dir = vec3(rxy*cos(phi), rxy*sin(phi), z);

    // wavelength sampling: uniform in [lambda0-dlambda, lambda0+dlambda]
    double u3 = rng_uniform01(rng);
    double lambda = src->lambda0 + (2.0*u3 - 1.0)*src->dlambda;

    Particle p = particle_make(pos, dir);
    p.lambda = lambda;

    double pmul = src->flux != 0.0 ? src->flux : 1.0 / (4.0 * M_PI);

    p.p = pmul;

    return p;
}
