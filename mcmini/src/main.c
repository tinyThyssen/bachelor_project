#include <stdio.h>
#include "rng.h"
#include "vec3.h"
#include "source_div.h"
#include "source_simple.h"
#include "monitor_flat.h"
#include "monitor_sphere.h"
#include "scatterer_sphere.h"
#include <math.h>

int main(void) {
    RNG rng;
    rng_seed(&rng, 42, 54);

    // // Match McStas Source_div settings exactly
    // SourceDiv src = {
    //     .center   = vec3(0.0, 0.0, 0.0),

    //     .xwidth   = 0.4,     // m
    //     .yheight  = 0.4,     // m

    //     .focus_aw = 10,    // deg (horizontal divergence width)
    //     .focus_ah = 10,    // deg (vertical divergence width)
    //     .gauss    = 0,       // 0=uniform, 1=gaussian (McStas default is 0)

    //     .lambda0  = 5.0,     // Angstrom
    //     .dlambda  = 0.5      // Angstrom half-spread (=> [4.5, 5.5])
    // };



    // matched mcstas source_simple
    SourceSimple src = {
        .center = vec3(0.0, 0.0, -1.0),

        .radius = 0.2,      // m, radius of circular source area (in x-y plane). If 0, then it's a point source.

        .dist = 1.5,       // m
        .focus_xw = 1.0,    // m (horizontal focus width)
        .focus_yh = 1.0,    // m (vertical focus height)

        .E0 = 25.0,        // meV
        .dE = 2.5,         // meV half-width (=> [22.5, 27.5])
        .lambda0 = 5.0,    // Angstrom
        .dlambda = 0.5,    // Angstrom half-width (=> [4.5, 5.5])

        .flux = 1.0,       // arbitrary units (since we will normalize monitor by n_history)
        .gauss = 0         // 0=flat, 1=gaussian distribution for energy and wavelength
    };



    long long Nsim = 100000;


    // multiple scattering test for solid sphere
    ScattererSphere sph;
    MonitorSphere mon;
    scatterer_sphere_init(&sph);

    sph.center = vec3(0.0, 0.0, 0.0);
    sph.radius = 0.5; // m

    if (!monitor_sphere_open_binned(&mon, "solid_sphere_multiple_scatter.csv",
                                  vec3(0.0, 0.0, 0.0), 1.5, // center and radius
                                  360, 180, Nsim)) { // nx, ny, n_history
        printf("Failed to open monitor\n");
        return 1;
    }

    for (long long i = 0; i < Nsim; i++) {
        Particle p = source_simple_emit(&src, &rng);

        int scat_count = 0;
        while (p.alive) {
            ScattererEvent ev = scatterer_sphere_interact(&sph, &p, &rng);

            if (ev == SPHERE_NO_HIT) break;       // never hits sample
            if (ev == SPHERE_TRANSMIT) break;     // left sample without interacting
            if (ev == SPHERE_ABSORB) break;       // killed inside
            if (ev == SPHERE_SCATTER) {
                scat_count++;
                if (sph.max_scat > 0 && scat_count >= sph.max_scat) {
                    // give up: treat as transmitted (or just stop)
                    break;
                }
            }
        }

        monitor_sphere_record(&mon, &p);

    }
    monitor_sphere_normalize_per_history(&mon); // optional, if wanted
    monitor_sphere_close(&mon);                 // required


    // // code for monitor sphere (binned)
    // MonitorSphere mon;
    // if (!monitor_sphere_open_binned(&mon, "sphere_hits_binned_srcsimple.csv",
    //                               vec3(0,0,0), 1.5, // center and radius
    //                               360, 180, Nsim)) { // nx, ny, n_history
    //     printf("Failed to open monitor\n");
    //     return 1;
    // }

    // for (long long i = 0; i < Nsim; i++) {
    //     Particle p = source_simple_emit(&src, &rng);
    //     monitor_sphere_record(&mon, &p);
    // }

    // // Option 1: McStas-ish per-history intensity
    // monitor_sphere_normalize_per_history(&mon);
    // // Option 2: additionally match McStas reported I (presentation)
    // /// monitor_sphere_scale_to_total_I(&mon, 0.00194955);
    // monitor_sphere_close(&mon);




    // // code for monitor flat (binned)
    // MonitorFlat mon;
    // if (!monitor_flat_open_binned(&mon, "flat_hits_binned_srcsimple.csv",
    //                             vec3(0,0,1.5), 0.5, 0.5, // center, xwidth, yheight
    //                             200, 200, Nsim)) {
    //     printf("Failed to open monitor\n");
    //     return 1;
    // }

    // for (long long i = 0; i < Nsim; i++) {
    //     Particle p = source_simple_emit(&src, &rng);
    //     monitor_flat_record(&mon, &p);
    // }

    // // Option 1: McStas-ish per-history intensity
    // monitor_flat_normalize_per_history(&mon);

    // // Option 2: additionally match McStas reported I (presentation)
    // /// monitor_flat_scale_to_total_I(&mon, 0.00194955);

    // monitor_flat_close(&mon);





    // // Match McStas PSD_monitor placement and size
    // MonitorFlat mon;
    // if (!monitor_flat_open(&mon, "flat_hits.csv", vec3(0.0, 0.0, 1.5), 0.5, 0.5)) {
    //     printf("Failed to open monitor output\n");
    //     return 1;
    // }

    // for (long i = 0; i < 1000000; i++) {
    //     Particle p = source_div_emit(&src, &rng);
    //     monitor_flat_record(&mon, &p);
    // }

    // monitor_flat_close(&mon);




    return 0;
}

