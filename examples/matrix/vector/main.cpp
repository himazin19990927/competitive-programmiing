#include <iostream>
using namespace std;

struct Vec3 {
    int x, y, z;

    Vec3(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
};

Vec3 operator+(const Vec3 &left, const Vec3 &right) {
    int x = left.x + right.x;
    int y = left.y + right.y;
    int z = left.z + right.z;
    return Vec3(x, y, z);
}

Vec3 operator-(const Vec3 &left, const Vec3 &right) {
    int x = left.x - right.x;
    int y = left.y - right.y;
    int z = left.z - right.z;
    return Vec3(x, y, z);
}

Vec3 operator*(const int &left, const Vec3 &right) {
    int x = left * right.x;
    int y = left * right.y;
    int z = left * right.z;
    return Vec3(x, y, z);
}

Vec3 operator*(const Vec3 &left, const int &right) {
    int x = left.x * right;
    int y = left.y * right;
    int z = left.z * right;
    return Vec3(x, y, z);
}

int operator*(const Vec3 &left, const Vec3 &right) {
    int result = left.x * right.x + left.y * right.y + left.z * right.z;
    return result;
}

ostream &operator<<(ostream &stream, const Vec3 &v) {
    stream << "[" << v.x << ", " << v.y << ", " << v.z << "]";
    return stream;
}

int main() {
    int k = 3;
    Vec3 a(1, 2, 3);
    Vec3 b(4, 5, 6);

    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " * " << b << " = " << a * b << endl;

    cout << a << " * " << k << " = " << a * k << endl;
    cout << k << " * " << b << " = " << k * b << endl;
}