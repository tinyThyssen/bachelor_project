#include <stdio.h>
#include "rng.h"
#include "source_disk.h"
#include <math.h>

int main(void) {
    RNG rng;
    rng_seed(&rng, 42, 54);

    SourceDisk src = {
        .center = {0.0, 0.0, 0.0},
        .radius = 0.02
    };

    Particle p;
    for (int i = 0; i < 50; i++) {
        p = source_disk_emit(&src, &rng);
        printf("r = (%.5f %.5f %.5f)\n", p.r.x, p.r.y, p.r.z);
        printf("vec = (%.5f %.5f %.5f)\n", p.vec.x, p.vec.y, p.vec.z); 
    }

    return 0;
}
