#ifndef MONITOR_CYLINDER_H
#define MONITOR_CYLINDER_H

#include "particle.h"
#include <stdio.h>

typedef enum {
    MONITOR_CYLINDER_EVENTS = 0,
    MONITOR_CYLINDER_BINNED = 1, // for binned output
} MonitorCylinderMode;

typedef struct {
    Vec3 center;
    double radius;
    double yheight;

    MonitorCylinderMode mode;
    FILE *fpt;

    // binned
    int nr, ny;
    long long n_history; // number of particle histories (for normalization)
    long long hits_total;
    long long hits_in;

    // bins in (phi, y)
    double phi_min, phi_max;    // [-180, 180) degrees
    double y_min, y_max;        // vertical bounds in meters
    double *I;               // size nr*ny
    double *sum_w2;          // size nr*ny, stores sum of squared weights for variance estimates

    // beamstop settings
    int beamstop_enabled;
    double beamstop_radius;
    Vec3 beamstop_center;

    // if nonzero, binned mode uses only the ray direction for angular binning
    int direction_only;
} MonitorCylinder;


int monitor_cylinder_open(MonitorCylinder *m, const char *path, Vec3 center,
                          double radius, double yheight);

int monitor_cylinder_open_binned(MonitorCylinder *m, const char *path, Vec3 center,
                                 double radius, double yheight,
                                 int nr, int ny, long long n_history);

void monitor_cylinder_close(MonitorCylinder *m);

// Record the first intersection of particle ray with the cylinder.
// Returns 1 if hit recorded, 0 if no forward hit.
int monitor_cylinder_record(MonitorCylinder *m, const Particle *p);

void monitor_cylinder_normalize_per_history(MonitorCylinder *m);          // I <- I / n_history
void monitor_cylinder_scale_to_total_I(MonitorCylinder *m, double Itarget); // I <- I * Itarget/sum(I)

#endif
