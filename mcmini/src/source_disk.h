#ifndef SOURCE_DISK_H
#define SOURCE_DISK_H

#include "particle.h"
#include "rng.h"

typedef struct {
    Vec3 center;
    double radius;
    double lambda_mean; // mean wavelength in angstroms
    double lambda_stddev; // standard deviation of wavelength in angstroms
} SourceDisk;

Particle source_disk_emit(const SourceDisk *src, RNG *rng);


#endif
