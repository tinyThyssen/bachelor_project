#include "rng.h"

static uint32_t rot32(uint32_t x, unsigned r) {
    return (x >> r) | (x << ((32 - r) & 31));
}

void rng_seed(RNG *rng, uint64_t state, uint64_t seq) {
    rng->state = 0;
    rng->inc = (seq << 1u) | 1u;
    rng_u32(rng);
    rng->state += state;
    rng_u32(rng);
}

uint32_t rng_u32(RNG *rng) {
    uint64_t old = rng->state;
    rng->state = old * 6364136223846793005ULL + rng->inc;
    uint32_t xorshifted = (uint32_t)(((old >> 18u) ^ old) >> 27u);
    uint32_t rot = old >> 59u;
    return rot32(xorshifted, rot);
}

// return random number in [0, 1)
double rng_uniform01(RNG *rng) {
    return rng_u32(rng) / 4294967296.0;
}

// generate random number in [min, max)
double rng_uniform_range(RNG *rng, double min, double max) {
    return min + (max - min) * rng_uniform01(rng);
}
