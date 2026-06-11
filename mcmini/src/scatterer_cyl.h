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

    double radius;
    double height;

    // Material/physics parameters
    double sigma_abs; // absorption cross section [barn] at 2200 m/s
    double sigma_inc; // incoherent scattering cross section [barn]
    double VcA3; // unit cell volume [Å^3]
    double pack; // packing factor [0..1]
    // double p_interact; // probability to force interaction (variance reduction), typical 1.0
    // int order; // 1 => single scattering only (recommended for "simple")

    //  Options
    int enable_absorption;  // 1 enable absorption, 0 disable
    int enable_scattering;  // 1 enable scattering, 0 disable
    int max_scat;
} ScattererCyl;

// Event types for scatterer interaction outcomes
typedef enum {
    CYLINDER_NO_HIT = 0,     // ray does not intersect cylinder
    CYLINDER_TRANSMIT = 1,   // intersects but no interaction (transmitted)
    CYLINDER_SCATTER = 2,    // scattered (direction/energy may change)
    CYLINDER_ABSORB = 3      // absorbed (particle killed)
} ScattererEvent;

// Initialize scatterer struct with default parameters (vanadium-like)
void scatterer_cyl_init(ScattererCyl *s);

/*
  Interact a particle with the cylinder.
  - Computes intersection with cylinder geometry
  - Samples free path + decides scatter vs absorption vs transmit
  - Updates particle in-place (position, direction, weight, alive, etc.)
  - Returns event type
*/
ScattererEvent scatterer_cyl_interact(const ScattererCyl *s, Particle *p, RNG *rng);

#endif // SCATTERER_CYL_H
