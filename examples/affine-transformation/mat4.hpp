#ifndef AFFINE_TRANFORMATION_MAT4
#define AFFINE_TRANFORMATION_MAT4

#include <vector>

struct mat4 {
    std::vector<std::vector<float>> data;

    mat4(std::vector<std::vector<float>> data);

    static mat4 identity();

    static mat4 translate(float x, float y, float z);
    static mat4 rotate(float x, float y, float z, float rad);
    static mat4 rotate_axis_x(float rad);
    static mat4 rotate_axis_y(float rad);
    static mat4 rotate_axis_z(float rad);
};

mat4 operator*(const mat4 &left, const mat4 &right);
#endif