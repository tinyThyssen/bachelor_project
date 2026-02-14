#ifndef MONITOR_SPHERE_H
#define MONITOR_SPHERE_H

#include "particle.h"
#include <stdio.h>

typedef struct {
    Vec3 center;
    double radius;

    // simple “event list” output for now
    FILE *fpt;
} MonitorSphere;


int monitor_sphere_open(MonitorSphere *m, const char *path, Vec3 center, double radius);
void monitor_sphere_close(MonitorSphere *m);

// Record the first intersection of particle ray with the sphere.
// Returns 1 if hit recorded, 0 if no forward hit.
int monitor_sphere_record(MonitorSphere *m, const Particle *p);

#endif
