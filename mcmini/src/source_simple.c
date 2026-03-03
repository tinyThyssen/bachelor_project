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
    Vec3 dvec = v_sub(target, pos);
    double dist_p = sqrt(v_dot(dvec, dvec));
    Vec3 dir = v_scale(dvec, 1.0 / dist_p);

    // wavelength sampling: uniform in [lambda0-dlambda, lambda0+dlambda]
    double u5 = rng_uniform01(rng);
    double lambda = src->lambda0 + (2.0*u5 - 1.0)*src->dlambda;

    Particle p = particle_make(pos, dir);
    p.lambda = lambda;
    /*
    Each pixel is now the weighted sum of neutron probabilities. 
    The probability p of each neutron is the product of the source flux distribution (pmul) 
    and the geometric factor (pdir) that accounts for the focusing and distance.
    */
    double src_area = 0.0;
    if (src->radius > 0.0) {
        src_area = M_PI * src->radius * src->radius;
    } else {
        src_area = src->xwidth * src->yheight;
    }

    // In our setup target center is on +z axis at distance src->dist from source center.
    double dz = target.z - pos.z;
    double pdir = 0.0;
    if (src->focus_xw > 0.0 && src->focus_yh > 0.0 && dist_p > 0.0) {
        double cos_theta = dz / dist_p;
        pdir = (src->focus_xw * src->focus_yh) / (dist_p * dist_p);
        // order=2 in McStas Source_simple call
        pdir *= cos_theta * cos_theta;
    }

    double pmul;
    if (src->flux != 0.0) {
        pmul = src->flux * 1e4 * src_area;
        if (src->dlambda > 0.0) {
            pmul *= 2.0 * src->dlambda;
        } else if (src->dE > 0.0) {
            pmul *= 2.0 * src->dE;
        }
    } else {
        pmul = 1.0 / (4.0 * M_PI);
    }

    p.p = pmul * pdir;
    return p;
}
