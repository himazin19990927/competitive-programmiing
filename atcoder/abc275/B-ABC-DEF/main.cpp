#include <bits/stdc++.h>
using namespace std;

const int IINF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr int INF = sizeof(int) == sizeof(long long) ? LINF : IINF;
const double eps = 1e-15;
const long long V = 998244353;
long long mod(long long x) { return x % V; }

int main() {
    long long A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;

    A = mod(A);
    B = mod(B);
    C = mod(C);
    D = mod(D);
    E = mod(E);
    F = mod(F);

    long long r0 = mod(mod(A * B) * C);
    long long r1 = mod(mod(D * E) * F);
    long long res = mod(r0 + V - r1);

    cout << res << endl;
}