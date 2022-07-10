#include <bits/stdc++.h>
using namespace std;

const int IINF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr int INF = sizeof(int) == sizeof(long long) ? LINF : IINF;
const double eps = 1e-15;

int main() {
    int N, M, X, T, D;
    cin >> N >> M >> X >> T >> D;

    int L_0th = T - D * X;

    if(M > X) {
        cout << T << endl;
    } else {
        cout << L_0th + D * M << endl;
    }
}