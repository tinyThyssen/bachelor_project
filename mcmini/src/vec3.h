#ifndef VEC3_H
#define VEC3_H

typedef struct {
    double x, y, z;
} Vec3;


Vec3 vec3(double x, double y, double z);
Vec3 v_add(Vec3 vec_a, Vec3 vec_b);
Vec3 v_scale(Vec3 vec_a, double scalar);
double v_dot(Vec3 vec_a, Vec3 vec_b);
double v_norm(Vec3 vec_a);
Vec3 v_normalize(Vec3 vec_a);
#endif
