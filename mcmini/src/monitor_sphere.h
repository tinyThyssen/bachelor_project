#ifndef MONITOR_SPHERE_H
#define MONITOR_SPHERE_H

#include "particle.h"
#include <stdio.h>

typedef enum {
    MONITOR_SPHERE_EVENTS = 0,
    MONITOR_SPHERE_BINNED = 1, // for binned output
} MonitorSphereMode;

typedef struct {
    Vec3 center;
    double radius;

    MonitorSphereMode mode;
    FILE *fpt;

    // binned
    int nx, ny;
    long long n_history; // number of particle histories (for normalization)
    long long hits_total;
    long long hits_in;

    // bins in (phi, theta)
    double phi_min, phi_max; // [-180, 180) degrees
    double theta_min, theta_max;   // [-90, 90] degrees
    double *I;               // size nx*ny

    // beamstop settings
    int beamstop_enabled;
    double beamstop_radius;
    Vec3 beamstop_center;
} MonitorSphere;



int monitor_sphere_open(MonitorSphere *m, const char *path, Vec3 center, double radius);

int monitor_sphere_open_binned(MonitorSphere *m, const char *path, Vec3 center, double radius,
                             int nx, int ny, long long n_history);

void monitor_sphere_close(MonitorSphere *m);

// Record the first intersection of particle ray with the sphere.
// Returns 1 if hit recorded, 0 if no forward hit.
int monitor_sphere_record(MonitorSphere *m, const Particle *p);

void monitor_sphere_normalize_per_history(MonitorSphere *m);          // I <- I / n_history
void monitor_sphere_scale_to_total_I(MonitorSphere *m, double Itarget); // I <- I * Itarget/sum(I)

#endif
