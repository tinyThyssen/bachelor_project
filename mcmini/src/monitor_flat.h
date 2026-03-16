#ifndef MONITOR_FLAT_H
#define MONITOR_FLAT_H

#include "particle.h"
#include <stdio.h>

typedef enum {
    MONITOR_FLAT_EVENTS = 0,
    MONITOR_FLAT_BINNED = 1
} MonitorFlatMode;

typedef struct {
    // geometry
    Vec3 center;
    Vec3 normal;      // default (0,0,1)
    double xwidth;    // [m]
    double yheight;   // [m]

    // mode
    MonitorFlatMode mode;

    // event list output
    FILE *fpt;

    // binned output
    int nx, ny;
    double xmin, xmax, ymin, ymax;
    double *I;        // intensity sum per bin (row-major: iy*nx + ix)
    double *L;        // weighted wavelength sum per bin: sum(p*lambda)
    long long hits_total;
    long long hits_in;

    // normalization (optional but useful)
    long long n_history;   // total launched rays in run (for I/N)
} MonitorFlat;

// Existing: event list
int  monitor_flat_open(MonitorFlat *m, const char *path, Vec3 center, double xwidth, double yheight);



// New: binned (McStas-like)
int  monitor_flat_open_binned(MonitorFlat *m, const char *path, Vec3 center,
                              double xwidth, double yheight, int nx, int ny,
                              long long n_history);

// Record one ray (works for both modes)
int  monitor_flat_record(MonitorFlat *m, const Particle *p);

// Close + write output (works for both modes)
void monitor_flat_close(MonitorFlat *m);

// Optional: post-run scaling for binned output
void monitor_flat_normalize_per_history(MonitorFlat *m);          // I <- I / n_history
void monitor_flat_scale_to_total_I(MonitorFlat *m, double Itarget); // I <- I * Itarget/sum(I)

#endif
