#include <iostream>
#include <limits>
#include <vector>
using namespace std;

template <class T> void chmin(T &a, T b) {
    if(a > b) {
        a = b;
    }
}

int N;
vector<long long> h;
vector<long long> dp;

long long rec(int i) {
    // DPの値が更新されていたら、その値を返す
    if(dp[i] < numeric_limits<long long>::max()) {
        return dp[i];
    }

    // ベースケース: 足場0のコストは0
    if(i == 0) {
        return 0;
    }

    // 答えを表す変数
    long long res = numeric_limits<long long>::max();

    // 足場 i - 1から来た場合
    chmin(res, rec(i - 1) + abs(h[i] - h[i - 1]));

    // 足場 i - 2から来た場合
    if(i > 1) {
        chmin(res, rec(i - 2) + abs(h[i] - h[i - 2]));
    }

    dp[i] = res;
    return res;
}

int main() {
    cin >> N;

    h.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> h[i];
    }

    dp.assign(N, numeric_limits<long long>::max());

    cout << rec(N - 1) << endl;
}