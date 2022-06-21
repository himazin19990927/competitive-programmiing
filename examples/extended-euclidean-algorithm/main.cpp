#include <iostream>
#include <tuple>
using namespace std;

tuple<int, int, int> extended_euclid(int a, int b) {
    // q[k-2], q[k-1], q[k]
    int q_2, q_1, q;

    // r[k-2], r[k-1], r[k]
    int r_2, r_1, r;

    // u[k-2], u[k-1], u[k]
    int u_2, u_1, u;

    // v[k-2], v[k-1], v[k]
    int v_2, v_1, v;

    r_2 = a;
    r_1 = b;
    r = -1;

    u_2 = 1;
    u_1 = 0;

    v_2 = 0;
    v_1 = 1;

    while (1) {
        q = r_2 / r_1;

        r = r_2 - q * r_1;
        u = u_2 - q * u_1;
        v = v_2 - q * v_1;

        if (r == 0) {
            break;
        }

        r_2 = r_1;
        r_1 = r;

        u_2 = u_1;
        u_1 = u;

        v_2 = v_1;
        v_1 = v;
    }

    return {r_1, u_1, v_1};
}

int main() {
    int a, b;
    cin >> a >> b;

    auto res = extended_euclid(a, b);
    int r = get<0>(res);
    int u = get<1>(res);
    int v = get<2>(res);

    cout << u << " * " << a << " + " << v << " * " << b << " = " << r << endl;
}