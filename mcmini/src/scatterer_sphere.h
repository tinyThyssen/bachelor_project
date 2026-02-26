#ifndef SCATTERER_SPHERE_H
#define SCATTERER_SPHERE_H

#include "vec3.h"
#include "particle.h"
#include "rng.h"
#include <stdio.h>

/*
  Simple hollow-sphere scatterer (vanadium-like):
  - Geometry: sphere centered at center
  - Supports solid sphere by setting inner_radius = 0 and inner_yheight = 0
*/
typedef struct {
    // Geometry (meters)
    Vec3 center; // sphere center position in world coords

    double radius; // sphere radius (in x-z plane)

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
    int max_scat; // maximum number of scatters to allow before giving up and transmitting (to prevent infinite loops in pathological cases). 0 or negative means no limit.
} ScattererSphere;

// Event types for scatterer interaction outcomes
typedef enum {
    SPHERE_NO_HIT = 0,     // ray does not intersect sphere
    SPHERE_TRANSMIT = 1,   // intersects but no interaction (transmitted)
    SPHERE_SCATTER = 2,    // scattered (direction/energy may change)
    SPHERE_ABSORB = 3      // absorbed (particle killed)
} ScattererEvent;

// Initialize scatterer struct with default parameters (vanadium-like)
void scatterer_sphere_init(ScattererSphere *s);

// records the intersections in csv file
int sphere_record_open(ScattererSphere *m, const char *path, Vec3 center, double radius);
void sphere_record_close(ScattererSphere *m);
int sphere_record_hit(ScattererSphere *m, const Particle *p);



/*
  Interact a particle with the sphere.
  - Computes intersection with hollow sphere geometry
  - Samples free path + decides scatter vs absorption vs transmit
  - Updates particle in-place (position, direction, weight, alive, etc.)
  - Returns event type
*/
ScattererEvent scatterer_sphere_interact(const ScattererSphere *s, Particle *p, RNG *rng);

#endif // SCATTERER_SPHERE_H
