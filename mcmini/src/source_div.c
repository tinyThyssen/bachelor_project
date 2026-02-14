#include "source_div.h"
#include "vec3.h"
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


Particle source_div_emit(const SourceDiv *src, RNG *rng)
{
    // sample uniform disk
    double u1 = rng_uniform01(rng); // uniform in [0, 1]
    double u2 = rng_uniform01(rng);     // uniform in [0, 1]

    double r = src->radius * sqrt(u1); // from src struct pull radius and multiply by sqrt of u1 to get radius of sampled point. sqrt is needed to ensure uniform distribution across disk area
    double phi = 2.0 * M_PI * u2; // uniform in [0, 2*pi]

    Vec3 pos = vec3( // from source disk center, add offset in x and y direction based on sampled radius and angle
        src->center.x + r * cos(phi), // from source disk center, add offset in x direction based on sampled radius and angle
        src->center.y + r * sin(phi), // from soruce center, y. add offset
        src->center.z
    );

    // sample target point on virtual focus plane
    double u3 = rng_uniform01(rng); // uniform in [0, 1]
    double u4 = rng_uniform01(rng); // uniform in [0, 1]

    double xt = (u3 - 0.5) * src->focus_xw; // uniform in [-focus_xw/2, focus_xw/2]
    double yt = (u4 - 0.5) * src->focus_yh; // uniform in [-focus_yh/2, focus_yh/2]
    double zt = src->center.z + src->dist; // target plane is at distance dist from source plane along +z

    Vec3 target = vec3(xt, yt, zt); // target point on virtual focus plane with coordinates (xt, yt, zt)

    /* Direction = normalized(target - pos) */
    Vec3 dir = v_normalize(v_sub(target, pos)); // direction vector from source point to target point, normalized to unit length

    // add variance in wavelength
    double u5 = rng_uniform01(rng);
    double lambda = src->lambda0 + (u5 - 0.5) * src->dlambda;

    if (lambda <= 0.0)
        lambda = src->lambda0;  // safety guard


    // create particle
    Particle p = particle_make(pos, dir);
    p.lambda = lambda;
    double speed = 3956.0 / lambda;
    p.v = v_scale(dir, speed);

    return p;
}
