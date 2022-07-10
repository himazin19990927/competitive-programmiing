#include <bits/stdc++.h>
using namespace std;

const int IINF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr int INF = sizeof(int) == sizeof(long long) ? LINF : IINF;
const double eps = 1e-15;

int main() {
    int a, b, d;
    cin >> a >> b >> d;

    double rad = d * (M_PI / 180);

    double p_x = a * cos(rad) - b * sin(rad);
    double p_y = a * sin(rad) + b * cos(rad);

    cout << setprecision(20);
    cout << p_x << " " << p_y << endl;
}