#include <bits/stdc++.h>
using namespace std;

const int IINF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr int INF = sizeof(int) == sizeof(long long) ? LINF : IINF;
const double eps = 1e-15;

int64_t round_off(int64_t X, int64_t K) {
    for(int i = 0; i < K; i++) {
        X /= 10;
    }

    int mod = X % 10;
    if(mod < 5) {
        X -= mod;
    } else {
        X += (10 - mod);
    }

    for(int i = 0; i < K; i++) {
        X *= 10;
    }

    return X;
}

int main() {
    int64_t X, K;
    cin >> X >> K;

    int64_t result = X;
    for(int i = 0; i < K; i++) {
        result = round_off(result, i);
    }

    cout << result << endl;
}