#include "vec3.h"
#include <math.h>

Vec3 vec3(double x, double y, double z) {
    Vec3 vec = {x, y, z};
    return vec;
}

Vec3 v_add(Vec3 vec_a, Vec3 vec_b) {
    return vec3(vec_a.x + vec_b.x, vec_a.y + vec_b.y, vec_a.z + vec_b.z);
}

Vec3 v_scale(Vec3 vec_a, double scalar) {
    return vec3(vec_a.x * scalar, vec_a.y * scalar, vec_a.z * scalar);
}

double v_dot(Vec3 vec_a, Vec3 vec_b) {
    return vec_a.x*vec_b.x + vec_a.y*vec_b.y + vec_a.z*vec_b.z;
}

double v_norm(Vec3 vec_a) {
    return sqrt(v_dot(vec_a, vec_a));
}

Vec3 v_normalize(Vec3 vec_a) {
    double n = v_norm(vec_a);

    if (n > 0.0) {
        return v_scale(vec_a, 1.0/n);
    } else {
        return vec3(0, 0, 0);
    }
}
