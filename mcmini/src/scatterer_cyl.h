#ifndef SCATTERER_CYL_H
#define SCATTERER_CYL_H

#include "vec3.h"
#include "particle.h"
#include "rng.h"
#include <stdio.h>

/*
  Simple hollow-cylinder scatterer (vanadium-like):
  - Geometry: cylinder aligned with +y (matches many McStas components)
  - Supports solid cylinder by setting inner_radius = 0 and inner_yheight = 0
*/
typedef struct {
    // Geometry (meters)
    Vec3 center; // cylinder center position in world coords

    double R_out; // outer radius (in x-z plane)
    double R_in; // inner radius (in x-z plane, 0 => solid)
    double H_out; // outer height (extent along y)
    double H_in; // inner height (extent along y, 0 => same as outer, but usually H_out-2*thickness)

    // Material/physics parameters
    double sigma_abs; // absorption cross section [barn] at 2200 m/s
    double sigma_inc; // incoherent scattering cross section [barn]
    double Vc; // unit cell volume [Å^3]
    double pack; // packing factor [0..1]
    double p_interact; // probability to force interaction (variance reduction), typical 1.0
    int order; // 1 => single scattering only (recommended for "simple")

    //  Options
    int enable_absorption;  // 1 enable absorption, 0 disable
    int enable_scattering;  // 1 enable scattering, 0 disable
} ScattererCyl;

// Event types for scatterer interaction outcomes
typedef enum {
    SCATTERER_NO_HIT = 0,     // ray does not intersect cylinder
    SCATTERER_TRANSMIT = 1,   // intersects but no interaction (transmitted)
    SCATTERER_SCATTER = 2,    // scattered (direction/energy may change)
    SCATTERER_ABSORB = 3      // absorbed (particle killed)
} ScattererEvent;

// Initialize scatterer struct with default parameters (vanadium-like)
void scatterer_cyl_init(ScattererCyl *s);

// records the intersections in csv file
int cyl_record_open(ScattererCyl *m, const char *path, Vec3 center, double radius);
void cyl_record_close(ScattererCyl *m);
int cyl_record_hit(ScattererCyl *m, const Particle *p);



/*
  Interact a particle with the cylinder.
  - Computes intersection with hollow cylinder geometry
  - Samples free path + decides scatter vs absorption vs transmit
  - Updates particle in-place (position, direction, weight, alive, etc.)
  - Returns event type
*/
ScattererEvent scatterer_cyl_interact(const ScattererCyl *s, Particle *p, RNG *rng);

#endif // SCATTERER_CYL_H
