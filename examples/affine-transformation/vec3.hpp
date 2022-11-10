#ifndef AFFINE_TRANFORMATION_VEC3
#define AFFINE_TRANFORMATION_VEC3

#include "mat4.hpp"
#include <iostream>

struct vec3 {
    float x;
    float y;
    float z;
    vec3() : x(0), y(0), z(0) {}
    vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

    float magnitude() const;
    vec3 normalized() const;
    vec3 transform(const mat4 &matrix);
};

vec3 operator+(const vec3 &left, const vec3 &right);

vec3 operator-(const vec3 &left, const vec3 &right);
vec3 operator*(const float &left, const vec3 &right);
vec3 operator*(const vec3 &left, const float &right);
vec3 operator/(const vec3 &left, const float &right);

std::ostream &operator<<(std::ostream &stream, const vec3 &v);

#endif