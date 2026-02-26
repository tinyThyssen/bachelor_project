#ifndef SOURCE_SIMPLE_H
#define SOURCE_SIMPLE_H

#include "particle.h"
#include "rng.h"

typedef struct {
    Vec3 center;
    double radius; // m, radius of circle where neutrons are generated. Circle is in (x,y,0) plane, centered at center. If radius=0, then it's a point source.
    double yheight; // Height of rectangle in (x,y,0) plane where neutrons are generated.
    double xwidth; // width of rectangle

    double dist; // m, dist from source to along z
    double focus_xw; // width of target
    double focus_yh; // height of target

    double E0; // 	Mean energy of neutrons.
    double dE; // energy spread of neutrons. flat or gaussian
    double lambda0; // mean wavelength of neutrons
    double dlambda; // wavelength spread of neutrons. flat or gaussian

    double flux; // 1/(s*cm**2*st*energy unit)	flux per energy unit, Angs or meV if flux=0, the source emits 1 in 4*PI whole space.
    int gauss; // 0=flat, 1=gaussian distribution for energy and wavelength
} SourceSimple;

Particle source_simple_emit(const SourceSimple *src, RNG *rng);

#endif
