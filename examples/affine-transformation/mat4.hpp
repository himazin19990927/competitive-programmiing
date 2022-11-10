#ifndef AFFINE_TRANFORMATION_MAT4
#define AFFINE_TRANFORMATION_MAT4

#include <cmath>
#include <vector>

struct mat4 {
    std::vector<std::vector<float>> data;

    mat4(std::vector<std::vector<float>> data) : data(data) {}

    static mat4 identity() {
        return mat4({{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}});
    }

    static mat4 translate(float x, float y, float z) {
        return mat4({{1, 0, 0, x}, {0, 1, 0, y}, {0, 0, 1, z}, {0, 0, 0, 1}});
    }

    static mat4 rotate(float rx, float ry, float rz, float rad) {
        const float sin = std::sin(rad);
        const float cos = std::cos(rad);

        std::vector<float> m0 = {cos + (1 - cos) * rx * rx,
                                 (1 - cos) * rx * ry - rz * sin,
                                 (1 - cos) * rz * rx + ry * sin, 0};
        std::vector<float> m1 = {(1 - cos) * rx * ry + rz * sin,
                                 cos + (1 - cos) * ry * ry,
                                 (1 - cos) * ry * rz - rx * sin, 0};
        std::vector<float> m2 = {(1 - cos) * rz * rx - ry * sin,
                                 (1 - cos) * ry * rz + rx * sin,
                                 cos + (1 - cos) * rz * rz, 0};
        std::vector<float> m3 = {0, 0, 0, 1};

        return mat4({m0, m1, m2, m3});
    }
    static mat4 rotate_axis_x(float rad) { return mat4::rotate(1, 0, 0, rad); }
    static mat4 rotate_axis_y(float rad) { return mat4::rotate(0, 1, 0, rad); }
    static mat4 rotate_axis_z(float rad) { return mat4::rotate(0, 0, 1, rad); }

    mat4 operator*(const mat4 &right) {
        const int matrix_size = 4;

        mat4 result(std::vector<std::vector<float>>(
            matrix_size, std::vector<float>(matrix_size, 0)));
        for(int m = 0; m < matrix_size; m++) {
            for(int n = 0; n < matrix_size; n++) {
                for(int i = 0; i < matrix_size; i++) {
                    result.data[m][n] += this->data[m][i] * right.data[i][n];
                }
            }
        }

        return result;
    }
};

#endif