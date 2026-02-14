#ifndef SOURCE_DIV_H
#define SOURCE_DIV_H

#include "particle.h"
#include "rng.h"

typedef struct {
    Vec3 center;
    double radius;

    double focus_xw;
    double focus_yh;
    double dist;

    double lambda0;
    double dlambda;
} SourceDiv;

Particle source_div_emit(const SourceDiv *src, RNG *rng);

#endif
