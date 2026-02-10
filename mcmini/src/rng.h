#ifndef RNG_H
#define RNG_H

#include <stdint.h>

typedef struct {
    uint64_t state;
    uint64_t inc;
} RNG;

void rng_seed(RNG *rng, uint64_t state, uint64_t seq);
uint32_t rng_u32(RNG *rng);
double rng_uniform01(RNG *rng);
double rng_uniform_range(RNG *rng, double min, double max);

#endif
