#ifndef MONITOR_FLAT_H
#define MONITOR_FLAT_H

#include "particle.h"
#include <stdio.h>

typedef struct {
    Vec3 center;
    double xwidth; // length of side a (x direction)
    double yheight; // length of side b (y direction)

    // simple “event list” output for now
    FILE *fpt;
} MonitorFlat;


int monitor_flat_open(MonitorFlat *m, const char *path, Vec3 center, double xwidth, double yheight);
void monitor_flat_close(MonitorFlat *m);

// Record the first intersection of particle ray with the flat surface.
// Returns 1 if hit recorded, 0 if no forward hit.
int monitor_flat_record(MonitorFlat *m, const Particle *p);

#endif
