#include <cmath>
#include <iostream>

#include "mat4.hpp"
#include "vec3.hpp"

void test_operator(vec3 v1, vec3 v2, float a) {
    vec3 v3 = v1 + v2;
    std::cout << "v1 = " << v1.str() << std::endl;
    std::cout << "v2 = " << v2.str() << std::endl;
    std::cout << v1.str() << " + " << v2.str() << " = " << (v1 + v2).str()
              << std::endl;
    std::cout << v1.str() << " - " << v2.str() << " = " << (v1 - v2).str()
              << std::endl;
    std::cout << v1.str() << " * " << a << " = " << (v1 * a).str() << std::endl;
}

void test_translate(vec3 v1) {
    std::cout << "v1.transform(identity) = "
              << v1.transform(mat4::identity()).str() << std::endl;
    std::cout << "v1.transform(translate(10, 100, 1000)) = "
              << v1.transform(mat4::translate(10, 100, 1000)).str()
              << std::endl;
}

void test_rotation(vec3 v1) {
    std::cout << "v1.transform(rotateX(pi/2) = "
              << v1.transform(mat4::rotate_axis_x(M_PI / 2)).str() << std::endl;
    std::cout << "v1.transform(rotateY(pi/2) = "
              << v1.transform(mat4::rotate_axis_y(M_PI / 2)).str() << std::endl;
    std::cout << "v1.transform(rotateZ(pi/2) = "
              << v1.transform(mat4::rotate_axis_z(M_PI / 2)).str() << std::endl;
}

void test_magnitude(vec3 v1) {
    std::cout << "v1.magnitude() = " << v1.magnitude() << std::endl;
    std::cout << "v1.normalized() = " << v1.normalized().str() << std::endl;
}

int main() {
    vec3 v1, v2;
    std::cin >> v1.x >> v1.y >> v1.z;
    std::cin >> v2.x >> v2.y >> v2.z;

    float a;
    std::cin >> a;

    test_operator(v1, v2, a);
    test_translate(v1);
    test_rotation(v1);
    test_magnitude(v1);

    std::cout << "result = "
              << vec3()
                     .transform(mat4::translate(2, 1, 0) *
                                mat4::rotate_axis_x(M_PI / 2))
                     .str()
              << std::endl;
}
