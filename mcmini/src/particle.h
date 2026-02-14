#ifndef PARTICLE_H
#define PARTICLE_H

#include "vec3.h"

typedef struct {
    Vec3 r;      // position
    Vec3 vec;    // direction (unit vector)
    Vec3 v;      // velocity (not used in current implementation, but could be useful for future extensions)
    double t;    // time
    double p;    // weight
    double lambda; // wavelength
    int alive;   // 1 = alive, 0 = absorbed
} Particle;

static inline Particle particle_make(Vec3 r, Vec3 vec) {
    Particle p;
    p.r = r;
    p.vec = vec;
    p.v = vec3(0.0, 0.0, 0.0);
    p.t = 0.0;
    p.p = 1.0;
    p.lambda = 0.0;
    p.alive = 1;
    return p;
}


#endif
