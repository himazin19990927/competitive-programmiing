#include <bits/stdc++.h>
using namespace std;

const int IINF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr int INF = sizeof(int) == sizeof(long long) ? LINF : IINF;
const double eps = 1e-15;

int f(int n) {
    if(n == 0) {
        return 1;
    }

    return n * f(n - 1);
}

int main() {
    int N;
    cin >> N;

    cout << f(N) << endl;
}