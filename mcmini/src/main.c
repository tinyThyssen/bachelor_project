#include <stdio.h>
#include "rng.h"
#include "source_disk.h"
#include "source_div.h"
#include "monitor_sphere.h"
#include "monitor_flat.h"
#include <math.h>

int main(void) {
    RNG rng;
    rng_seed(&rng, 42, 54);

    SourceDiv src = {
        .center   = vec3(0.0, 0.0, 0.0),
        .radius   = 0.2,
        .dist     = 1.5,
        .focus_xw = 0.04,
        .focus_yh = 0.10,
        .lambda0  = 5.0,
        .dlambda  = 0.5
    };


    MonitorFlat mon;
    if (!monitor_flat_open(&mon, "flat_hits.csv", vec3(0,0,0.01), 0.25, 0.25)) {
        printf("Failed to open monitor output\n");
        return 1;
    }

    for (long i = 0; i < 10000; i++) {
        Particle p = source_div_emit(&src, &rng);
        monitor_flat_record(&mon, &p);
    }

    monitor_flat_close(&mon);


    return 0;
}
