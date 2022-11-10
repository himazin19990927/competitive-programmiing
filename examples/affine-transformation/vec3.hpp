#ifndef AFFINE_TRANFORMATION_VEC3
#define AFFINE_TRANFORMATION_VEC3

#include "mat4.hpp"
#include <cmath>
#include <iostream>
#include <string>

struct vec3 {
    float x;
    float y;
    float z;
    vec3() : x(0), y(0), z(0) {}
    vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

    vec3 operator+(const vec3 &right) {
        vec3 result;
        result.x = this->x + right.x;
        result.y = this->y + right.y;
        result.z = this->z + right.z;
        return result;
    }

    vec3 operator-(const vec3 &right) {
        vec3 result;
        result.x = this->x - right.x;
        result.y = this->y - right.y;
        result.z = this->z - right.z;
        return result;
    }

    vec3 operator*(const float &right) {
        vec3 result;
        result.x = this->x * right;
        result.y = this->y * right;
        result.z = this->z * right;
        return result;
    }

    vec3 operator/(const float &right) {
        vec3 result;
        result.x = this->x / right;
        result.y = this->y / right;
        result.z = this->z / right;
        return result;
    }

    float magnitude() const {
        return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
    }

    vec3 normalized() { return *this / this->magnitude(); }

    vec3 transform(const mat4 &matrix) {
        vec3 result;
        result.x = matrix.data[0][0] * x + matrix.data[0][1] * y +
                   matrix.data[0][2] * z + matrix.data[0][3];
        result.y = matrix.data[1][0] * x + matrix.data[1][1] * y +
                   matrix.data[1][2] * z + matrix.data[1][3];
        result.z = matrix.data[2][0] * x + matrix.data[2][1] * y +
                   matrix.data[2][2] * z + matrix.data[2][3];
        return result;
    }

    std::string str() {
        std::string s = "";
        s += "[";
        s += std::to_string(this->x);
        s += ", ";
        s += std::to_string(this->y);
        s += ", ";
        s += std::to_string(this->z);
        s += "]";
        return s;
    }
};

#endif