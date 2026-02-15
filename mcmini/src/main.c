#include <stdio.h>
#include "rng.h"
#include "source_div.h"
#include "monitor_flat.h"
#include "vec3.h"
#include <math.h>

int main(void) {
    RNG rng;
    rng_seed(&rng, 42, 54);

    // Match McStas Source_div settings exactly
    SourceDiv src = {
        .center   = vec3(0.0, 0.0, 0.0),

        .xwidth   = 0.4,     // m
        .yheight  = 0.4,     // m

        .focus_aw = 0.04,    // deg (horizontal divergence width)
        .focus_ah = 0.10,    // deg (vertical divergence width)
        .gauss    = 0,       // 0=uniform, 1=gaussian (McStas default is 0)

        .lambda0  = 5.0,     // Angstrom
        .dlambda  = 0.5      // Angstrom half-spread (=> [4.5, 5.5])
    };

    // Match McStas PSD_monitor placement and size
    MonitorFlat mon;
    if (!monitor_flat_open(&mon, "flat_hits.csv", vec3(0.0, 0.0, 1.5), 0.25, 0.25)) {
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
