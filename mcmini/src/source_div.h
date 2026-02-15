#ifndef SOURCE_DIV_H
#define SOURCE_DIV_H

#include "particle.h"
#include "rng.h"

typedef struct {
    Vec3 center;
    double xwidth;     // m
    double yheight;    // m

    double focus_aw;   // deg (horizontal divergence width)
    double focus_ah;   // deg (vertical divergence width)
    int gauss;         // 0 uniform, 1 Gaussian (FWHM)

    double lambda0;    // Ang
    double dlambda;    // Ang (half spread in McStas docs, see below)
} SourceDiv;

Particle source_div_emit(const SourceDiv *src, RNG *rng);

#endif
