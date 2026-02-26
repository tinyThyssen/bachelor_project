#include "source_simple.h"
#include "vec3.h"
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


Particle source_simple_emit(const SourceSimple *src, RNG *rng) {
    Vec3 pos;


    // if radius > 0, sample uniformly in circle. else from a rectangle with xwidth and yheight
    if (src->radius > 0.0) {
        // uniform disk
        double u1 = rng_uniform01(rng);
        double u2 = rng_uniform01(rng);
        double r   = src->radius * sqrt(u1);
        double phi = 2.0 * M_PI * u2;

        pos = vec3(src->center.x + r*cos(phi),
                   src->center.y + r*sin(phi),
                   src->center.z);
    } else {
        // uniform rectangle
        double u1 = rng_uniform01(rng);
        double u2 = rng_uniform01(rng);
        pos = vec3(src->center.x + (u1 - 0.5)*src->xwidth,
                   src->center.y + (u2 - 0.5)*src->yheight,
                   src->center.z);
    }

    // sample on the target
    double u3 = rng_uniform01(rng);
    double u4 = rng_uniform01(rng);

    double xt = src->center.x + (u3 - 0.5)*src->focus_xw;  // meters
    double yt = src->center.y + (u4 - 0.5)*src->focus_yh;  // meters
    double zt = src->center.z + src->dist;

    Vec3 target = vec3(xt, yt, zt);

    // normalize direction from source to target
    Vec3 dir = v_normalize(v_sub(target, pos));

    // wavelength sampling: uniform in [lambda0-dlambda, lambda0+dlambda]
    double u5 = rng_uniform01(rng);
    double lambda = src->lambda0 + (2.0*u5 - 1.0)*src->dlambda;

    Particle p = particle_make(pos, dir);
    p.lambda = lambda;
    return p;
}


