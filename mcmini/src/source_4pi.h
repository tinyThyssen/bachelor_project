#ifndef SOURCE_4PI_H
#define SOURCE_4PI_H

#include "particle.h"
#include "rng.h"

typedef struct {
    Vec3 center;
    double lambda0; // mean wavelength of neutrons
    double dlambda; // wavelength spread of neutrons. flat or gaussian

    double flux; // 1/(s*cm**2*st*energy unit)	flux per energy unit, Angs or meV if flux=0, the source emits 1 in 4*PI whole space.
    int gauss; // 0=flat, 1=gaussian distribution for energy and wavelength
} Source4Pi;

Particle source_4pi_emit(const Source4Pi *src, RNG *rng);

#endif
