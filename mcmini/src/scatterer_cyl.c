// scatterer_cyl.c
#include "scatterer_cyl.h"
#include "rng.h"
#include "vec3.h"

#include <math.h>
#include <stdio.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#ifndef INFINITY
#define INFINITY (1.0/0.0)
#endif




// Initialize scatterer struct with default parameters (vanadium-like)
void scatterer_cyl_init(ScattererCyl *s) {
    s->center = vec3(0.0, 0.0, 0.0);

    s->R_out = 0.1; // m
    s->R_in = 0.0; // m (0 => solid)
    s->H_out = 0.02; // m
    s->H_in = 0.0; // m (0 => same as outer, but usually H_out-2*thickness)

    s->sigma_abs = 0.4; // barn at 2200 m/s
    s->sigma_inc = 5.0; // barn
    s->Vc = 10.0; // Å^3
    s->pack = 0.6; // packing factor [0..1]

    s->p_interact = 1.0; // probability to force interaction (variance reduction), typical 1.0
    s->order = 1; // 1 => single scattering only (recommended for "simple")
    s->enable_absorption = 1; // enable absorption
    s->enable_scattering = 1; // enable scattering


}


// Interact a particle with the cylinder.
// - Computes intersection with hollow cylinder geometry
static int solid_cyl_interval_y(
    Vec3 r0, Vec3 vec, Vec3 cen,
    double R, double H,
    double *tin, double *tout)
{
    // radial interval
    double dx = r0.x - cen.x;
    double dz = r0.z - cen.z;

    double a = vec.x*vec.x + vec.z*vec.z;
    double b = 2.0*(dx*vec.x + dz*vec.z);
    double cc = dx*dx + dz*dz - R*R;

    double t_r_in = -INFINITY, t_r_out = INFINITY;

    if (fabs(a) < 1e-15) {
        // Ray parallel to y-axis: radius constant
        if (cc > 0.0) return 0; // outside cylinder forever
        // else: inside infinite cylinder for all t
    } else {
        double disc = b*b - 4.0*a*cc;
        if (disc < 0.0) return 0;
        double s = sqrt(disc);
        double t1 = (-b - s)/(2.0*a);
        double t2 = (-b + s)/(2.0*a);
        if (t1 > t2) { double tmp=t1; t1=t2; t2=tmp; }
        t_r_in = t1; t_r_out = t2;
    }

    // height slab interval
    double y_min = cen.y - H*0.5;
    double y_max = cen.y + H*0.5;

    double t_y_in = -INFINITY, t_y_out = INFINITY;

    if (fabs(vec.y) < 1e-15) {
        if (r0.y < y_min || r0.y > y_max) return 0; // never enters slab
    } else {
        double ty1 = (y_min - r0.y)/vec.y;
        double ty2 = (y_max - r0.y)/vec.y;
        if (ty1 > ty2) { double tmp=ty1; ty1=ty2; ty2=tmp; }
        t_y_in = ty1; t_y_out = ty2;
    }

    // --- overlap ---
    double t_in  = fmax(t_r_in,  t_y_in);
    double t_out = fmin(t_r_out, t_y_out);

    if (t_out < t_in) return 0;
    *tin = t_in;
    *tout = t_out;
    return 1;
}

// for debugging: records the intersections in csv file
static FILE *cyl_record_fpt = NULL;
int cyl_record_open(ScattererCyl *m, const char *path, Vec3 center, double radius) {
    m->center = center;
    m->R_out = radius;
    cyl_record_fpt = fopen(path, "w");
    if (!cyl_record_fpt) return 0;
    fprintf(cyl_record_fpt, "hit_x,hit_y,hit_z,dir_x,dir_y,dir_z,lambda\n");
    return 1;
}

void cyl_record_close(ScattererCyl *m) {
    m->center = vec3(0.0, 0.0, 0.0);
    m->R_out = 0.1;
    if (cyl_record_fpt) {
        fclose(cyl_record_fpt);
        cyl_record_fpt = NULL;
    }
}

int cyl_record_hit(ScattererCyl *m, const Particle *p) {
    m->center = vec3(0.0, 0.0, 0.0);
    if (cyl_record_fpt) {
        fprintf(cyl_record_fpt, "%g,%g,%g,%g,%g,%g,%g\n",
                p->r.x, p->r.y, p->r.z,
                p->vec.x, p->vec.y, p->vec.z,
                p->lambda);
    }
        return 1;
}




// ScattererEvent scatterer_cyl_interact(const ScattererCyl *s, Particle *p, RNG *rng) {
//     // cylinder parameters for convenience
//     Vec3 center = s->center;
//     double R_out = s->R_out;
//     double R_in = s->R_in;
//     double H_out = s->H_out;
//     double H_in = s->H_in;
//     Vec3 r0 = p->r; // ray origin
//     Vec3 dir = p->vec; // ray direction (unit vector)


//     // find material segments;
//     double o_in, o_out, i_in, i_out;
//     int hit_outer = solid_cyl_interval_y(r0, dir, center, R_out, H_out, &o_in, &o_out);
//     int hit_inner = (R_in > 0 && H_in > 0) ? solid_cyl_interval_y(r0, dir, center, R_in, H_in, &i_in, &i_out) : 0;


//     // if none → return NO_HIT;
//     if (!hit_outer || o_out < 0.0) {
//         return (ScattererEvent)0; // NO_HIT
//     }

//     // clamp entry to forward direction
//     if (o_in < 0.0) o_in = 0.0;

//     // segments: [o_in, o_out] is outer cylinder, [i_in, i_out] is inner cylinder (if hit_inner)
//     // material segment is outer minus inner, which can be 1 or 2 segments depending on whether inner is hit and how it overlaps with outer. We can compute the length of these segments
//     double seg1_len = 0.0, seg2_len = 0.0;
//     if (hit_inner) {
//         if (i_in > o_in) {
//             seg1_len = i_in - o_in; // first segment from o_in to in
//         }
//         if (i_out < o_out) {
//             seg2_len = o_out - i_out; // second segment from out to i_out
//         }
//     } else {
//         seg1_len = o_out - o_in; // single segment from o_in to o_out
//     }
    


//     // compute mu_s, mu_a, mu_t;
//     double sigma_inc = s->sigma_inc; // barn
//     double sigma_abs = s->sigma_abs; // barn
//     double Vc = s->Vc; // Å^3
//     double pack = s->pack; // packing factor [0..1]
//     double v = 3956 / p->lambda; // m/s, neutron velocity from wavelength (lambda in Angstrom)

//     double mu_s = (pack * sigma_inc / Vc) * 100.0; // 1/m
//     double mu_a_2200 = (pack * sigma_abs / Vc) * 100.0; // 1/m at 2200 m/s
//     double mu_a = mu_a_2200 * (2200.0 / v);
//     double mu_t = mu_s + mu_a;

//     int scatter_count = 0;

//     // for each segment {
//     double seg_len = seg1_len;

//     //     double L = segment_length;

//     //     while (L > 0) {

//     //         sample free path;

//     //         if no interaction:
//     //             break;

//     //         move particle;

//     //         if absorption:
//     //             p->alive = 0;
//     //             return ABSORB;

//     //         scatter:
//     //             sample new direction;
//     //             scatter_count++;

//     //             if order reached:
//     //                 return SCATTER;

//             // recompute remaining segments from new position;
//     //     }
//     // }

//     // return TRANSMIT;
//     return (ScattererEvent)1; // TRANSMIT
// }
