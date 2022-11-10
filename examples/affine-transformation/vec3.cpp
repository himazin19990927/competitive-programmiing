#include "vec3.hpp"
#include "mat4.hpp"

#include <cmath>

float vec3::magnitude() const {
    return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}

vec3 vec3::normalized() const { return *this / this->magnitude(); }

vec3 vec3::transform(const mat4 &matrix) {
    vec3 result;
    result.x = matrix.data[0][0] * x + matrix.data[0][1] * y +
               matrix.data[0][2] * z + matrix.data[0][3];
    result.y = matrix.data[1][0] * x + matrix.data[1][1] * y +
               matrix.data[1][2] * z + matrix.data[1][3];
    result.z = matrix.data[2][0] * x + matrix.data[2][1] * y +
               matrix.data[2][2] * z + matrix.data[2][3];
    return result;
}

vec3 operator+(const vec3 &left, const vec3 &right) {
    vec3 result;
    result.x = left.x + right.x;
    result.y = left.y + right.y;
    result.z = left.z + right.z;
    return result;
}

vec3 operator-(const vec3 &left, const vec3 &right) {
    vec3 result;
    result.x = left.x - right.x;
    result.y = left.y - right.y;
    result.z = left.z - right.z;
    return result;
}

vec3 operator*(const float &left, const vec3 &right) {
    vec3 result;
    result.x = left * right.x;
    result.y = left * right.y;
    result.z = left * right.z;
    return result;
}

vec3 operator*(const vec3 &left, const float &right) {
    vec3 result;
    result.x = left.x * right;
    result.y = left.y * right;
    result.z = left.z * right;
    return result;
}

vec3 operator/(const vec3 &left, const float &right) {
    vec3 result;
    result.x = left.x / right;
    result.y = left.y / right;
    result.z = left.z / right;
    return result;
}

std::ostream &operator<<(std::ostream &stream, const vec3 &v) {
    stream << '[' << v.x << ", " << v.y << ", " << v.z << ']';
    return stream;
}