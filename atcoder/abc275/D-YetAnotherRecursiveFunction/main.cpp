#include <bits/stdc++.h>
using namespace std;

const int IINF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr int INF = sizeof(int) == sizeof(long long) ? LINF : IINF;
const double eps = 1e-15;

long long f(long long N, std::map<long long, long long> &memo) {
    if(memo.count(N) != 0) {
        return memo[N];
    }

    long long result = f(N / 2, memo) + f(N / 3, memo);
    memo[N] = result;
    return result;
}

int main() {
    long long N;
    cin >> N;

    std::map<long long, long long> memo;
    memo[0] = 1;
    cout << f(N, memo) << endl;
}
