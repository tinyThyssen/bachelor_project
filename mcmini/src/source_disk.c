#include "source_disk.h"
#include <math.h>

Particle source_disk_emit(const SourceDisk *src, RNG *rng) {
    // sample uniform disk
    double u1 = rng_uniform01(rng);
    double u2 = rng_uniform01(rng);
    double r = src->radius * sqrt(u1);
    double phi_pt = 2.0 * M_PI * u2;

    Vec3 pos = {
        src->center.x + r * cos(phi_pt),
        src->center.y + r * sin(phi_pt),
        src->center.z
    };

    // Vec3 dir = {0.0, 0.0, 1.0}; // fixed beam along +z

    // uniformly sample direction in +z
    double alpha = 5 * M_PI / 180.0; // maximum angle from +z axis in radians (narrow beam)

    double u3 = rng_uniform01(rng); // uniform in [0, 1]
    double u4 = rng_uniform01(rng); // uniform in [0, 1]

    double cos_theta = cos(alpha) + (1 - cos(alpha)) * u3;   // uniform in [cos(alpha), 1]
    double sin_theta = sqrt(1.0 - cos_theta * cos_theta); // sin(theta) = sqrt(1 - cos^2(theta))

    double phi_dir = 2.0 * M_PI * u4; // uniform in [0, 2*pi]
    // convert spherical to Cartesian coordinates for direction vector
    Vec3 dir = {
        sin_theta * cos(phi_dir),
        sin_theta * sin(phi_dir),
        cos_theta
    };


    return particle_make(pos, dir);
}
