#ifndef PARTICLE_H
#define PARTICLE_H

#include "vec3.h"

typedef struct {
    Vec3 r;      // position
    Vec3 vec;    // direction (unit vector)
    double t;    // time
    double p;    // weight
    int alive;   // 1 = alive, 0 = absorbed
} Particle;

static inline Particle particle_make(Vec3 r, Vec3 vec) {
    Particle p;
    p.r = r;
    p.vec = vec;
    p.t = 0.0;
    p.p = 1.0;
    p.alive = 1;
    return p;
}

#endif
