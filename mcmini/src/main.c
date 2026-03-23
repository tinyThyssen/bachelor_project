#include <stdio.h>
#include "rng.h"
#include "vec3.h"
#include "source_div.h"
#include "source_simple.h"
#include "monitor_flat.h"
#include "monitor_sphere.h"
#include "scatterer_cyl.h"
#include <math.h>

int main(void) {
    RNG rng;
    rng_seed(&rng, 42, 54);

    SourceSimple src = {
        .center = vec3(0.0, 0.0, 0.0),
        .radius = 0.25,      // m, cylinder_height/2 to match solid_cylinder.instr
        .dist = 1.0,       // m
        .focus_xw = 0.5,    // m, 2*cylinder_radius + margin
        .focus_yh = 0.5,    // m, cylinder_height + margin

        .lambda0 = 4.0,    // Angstrom
        .dlambda = 0.1,    // Angstrom half-width (=> [3.9, 4.1])
        .flux = 1.0,       // arbitrary units (since we will normalize monitor by n_history)
        .gauss = 0         // 0=flat, 1=gaussian distribution for energy and wavelength
    };








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



    // // matched mcstas source_simple
    // SourceSimple src = {
    //     .center = vec3(0.0, 0.0, -0.1),

    //     .radius = 0.01,      // m, radius of circular source area (in x-y plane). If 0, then it's a point source.

    //     .dist = 1.0,       // m
    //     .focus_xw = 0.015,    // m (horizontal focus width)
    //     .focus_yh = 0.025,    // m (vertical focus height)

    //     // .E0 = 25.0,        // meV
    //     // .dE = 2.5,         // meV half-width (=> [22.5, 27.5])
    //     .lambda0 = 5.0,    // Angstrom
    //     .dlambda = 0.5,    // Angstrom half-width (=> [4.5, 5.5])

    //     .flux = 1.0,       // arbitrary units (since we will normalize monitor by n_history)
    //     .gauss = 0         // 0=flat, 1=gaussian distribution for energy and wavelength
    // };





    long long Nsim = 1e9; // number of simulated neutrons

    MonitorFlat mon;
    if (!monitor_flat_open_binned(&mon, "source_to_flat_monitor.csv",
                                vec3(0,0,1.0), 1.0, 1.0, // center, xwidth, yheight
                                2000, 2000, Nsim)) {
        printf("Failed to open monitor\n");
        return 1;
    }

    for (long long i = 0; i < Nsim; i++) {
        Particle p = source_simple_emit(&src, &rng);
        monitor_flat_record(&mon, &p);
    }

    monitor_flat_normalize_per_history(&mon); // optional, if wanted
    monitor_flat_close(&mon); // just test open and close for now. Will add recording and normalization later.

    // // multiple scattering test for solid cylinder
    // ScattererCyl cyl;
    // MonitorSphere mon_all;
    // MonitorSphere mon_by_scatter[5];
    // scatterer_cyl_init(&cyl);

    // cyl.center = vec3(0.0, 0.0, 0.0);
    // cyl.radius = 0.005; // m
    // cyl.height = 0.02; // m
    // cyl.VcA3 = 13.827; // match McStas unit_cell_volume
    // cyl.sigma_abs = 5.08; // barn at 2200 m/s (vanadium)
    // cyl.sigma_inc = 5.08; // barn (vanadium is mostly incoherent scatterer)
    // cyl.pack = 1.0; // typical packing factor for powder sample
    // // Match McStas my_absorption = 5.08*100/13.827 (which omits packing_factor):
    // // MCmini uses Sigma_abs = sigma_abs*100*pack/VcA3, so compensate by dividing by pack.
    // cyl.sigma_abs = 5.08 / cyl.pack;
    // if (!monitor_sphere_open_binned(&mon_all, "solid_cylinder_multiple_scatter.csv",
    //                               vec3(0.0, 0.0, 0.0), 1.0, // center and radius
    //                               360, 180, Nsim)) { // nx, ny, n_history
    //     printf("Failed to open monitor\n");
    //     return 1;
    // }
    // const char *scatter_files[5] = {
    //     "solid_cylinder_scatter_1.csv",
    //     "solid_cylinder_scatter_2.csv",
    //     "solid_cylinder_scatter_3.csv",
    //     "solid_cylinder_scatter_4.csv",
    //     "solid_cylinder_scatter_5.csv"
    // };
    // for (int s = 0; s < 5; s++) {
    //     if (!monitor_sphere_open_binned(&mon_by_scatter[s], scatter_files[s],
    //                                     vec3(0.0, 0.0, 0.0), 1.0, // center and radius
    //                                     360, 180, Nsim)) { // nx, ny, n_history
    //         printf("Failed to open scatter monitor %d\n", s + 1);
    //         return 1;
    //     }
    // }

    // for (long long i = 0; i < Nsim; i++) {
    //     Particle p = source_simple_emit(&src, &rng);

    //     int scat_count = 0;
    //     while (p.alive) {
    //         ScattererEvent ev = scatterer_cyl_interact(&cyl, &p, &rng);

    //         if (ev == CYLINDER_NO_HIT) break;       // never hits sample
    //         if (ev == CYLINDER_TRANSMIT) break;     // left sample without interacting
    //         if (ev == CYLINDER_ABSORB) break;       // killed inside
    //         if (ev == CYLINDER_SCATTER) {
    //             scat_count++;
    //             if (cyl.max_scat > 0 && scat_count >= cyl.max_scat) {
    //                 // give up: treat as transmitted (or just stop)
    //                 break;
    //             }
    //         }
    //     }

    //     if (p.alive && scat_count > 0) {
    //         monitor_sphere_record(&mon_all, &p);
    //         if (scat_count >= 1 && scat_count <= 5) {
    //             monitor_sphere_record(&mon_by_scatter[scat_count - 1], &p);
    //         }
    //     }

    // }
    // monitor_sphere_normalize_per_history(&mon_all); // optional, if wanted
    // monitor_sphere_close(&mon_all);                 // required
    // for (int s = 0; s < 5; s++) {
    //     monitor_sphere_normalize_per_history(&mon_by_scatter[s]);
    //     monitor_sphere_close(&mon_by_scatter[s]);
    // }





    // // multiple scattering test for solid cylinder
    // ScattererCyl cyl;
    // MonitorSphere mon_all;
    // MonitorSphere mon_by_scatter[5];
    // scatterer_cyl_init(&cyl);

    // cyl.center = vec3(0.0, 0.0, 0.0);
    // cyl.radius = 0.005; // m
    // cyl.height = 0.02; // m
    // cyl.VcA3 = 13.827; // match McStas unit_cell_volume
    // cyl.sigma_abs = 5.08; // barn at 2200 m/s (vanadium)
    // cyl.sigma_inc = 5.08; // barn (vanadium is mostly incoherent scatterer)
    // cyl.pack = 1.0; // typical packing factor for powder sample
    // // Match McStas my_absorption = 5.08*100/13.827 (which omits packing_factor):
    // // MCmini uses Sigma_abs = sigma_abs*100*pack/VcA3, so compensate by dividing by pack.
    // cyl.sigma_abs = 5.08 / cyl.pack;
    // if (!monitor_sphere_open_binned(&mon_all, "solid_cyl_r0p5h2_multiple_scatter.csv",
    //                               vec3(0.0, 0.0, 0.0), 1.0, // center and radius
    //                               360, 180, Nsim)) { // nx, ny, n_history
    //     printf("Failed to open monitor\n");
    //     return 1;
    // }
    // const char *scatter_files[5] = {
    //     "solid_cyl_r0p5h2_scatter_1.csv",
    //     "solid_cyl_r0p5h2_scatter_2.csv",
    //     "solid_cyl_r0p5h2_scatter_3.csv",
    //     "solid_cyl_r0p5h2_scatter_4.csv",
    //     "solid_cyl_r0p5h2_scatter_5.csv"
    // };
    // for (int s = 0; s < 5; s++) {
    //     if (!monitor_sphere_open_binned(&mon_by_scatter[s], scatter_files[s],
    //                                     vec3(0.0, 0.0, 0.0), 1.0, // center and radius
    //                                     360, 180, Nsim)) { // nx, ny, n_history
    //         printf("Failed to open scatter monitor %d\n", s + 1);
    //         return 1;
    //     }
    // }

    // mon_all.beamstop_enabled = 1;
    // mon_all.beamstop_radius = 0.08; // m, radial stop around +z beam axis on monitor sphere
    // mon_all.beamstop_center = vec3(mon_all.center.x, mon_all.center.y, mon_all.center.z + mon_all.radius); // center of beamstop on monitor sphere, placed on +z axis
    // for (int s = 0; s < 5; s++) {
    //     mon_by_scatter[s].beamstop_enabled = 1;
    //     mon_by_scatter[s].beamstop_radius = 0.08;
    //     mon_by_scatter[s].beamstop_center = vec3(mon_by_scatter[s].center.x,
    //                                              mon_by_scatter[s].center.y,
    //                                              mon_by_scatter[s].center.z + mon_by_scatter[s].radius);
    // }

    // for (long long i = 0; i < Nsim; i++) {
    //     Particle p = source_simple_emit(&src, &rng);

    //     int scat_count = 0;
    //     while (p.alive) {
    //         ScattererEvent ev = scatterer_cyl_interact(&cyl, &p, &rng);

    //         if (ev == CYLINDER_NO_HIT) break;       // never hits sample
    //         if (ev == CYLINDER_TRANSMIT) break;     // left sample without interacting
    //         if (ev == CYLINDER_ABSORB) break;       // killed inside
    //         if (ev == CYLINDER_SCATTER) {
    //             scat_count++;
    //             if (cyl.max_scat > 0 && scat_count >= cyl.max_scat) {
    //                 // give up: treat as transmitted (or just stop)
    //                 break;
    //             }
    //         }
    //     }

    //     if (p.alive) {
    //         monitor_sphere_record(&mon_all, &p);
    //         if (scat_count >= 1 && scat_count <= 5) {
    //             monitor_sphere_record(&mon_by_scatter[scat_count - 1], &p);
    //         }
    //     }

    // }
    // monitor_sphere_normalize_per_history(&mon_all); // optional, if wanted
    // monitor_sphere_close(&mon_all);                 // required
    // for (int s = 0; s < 5; s++) {
    //     monitor_sphere_normalize_per_history(&mon_by_scatter[s]);
    //     monitor_sphere_close(&mon_by_scatter[s]);
    // }







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
