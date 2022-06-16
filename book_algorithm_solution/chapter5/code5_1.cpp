#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long> h(N);
    for(int i = 0; i < N; i++) {
        cin >> h[i];
    }

    vector<long long> dp(N, LONG_LONG_MAX);

    // 初期条件
    dp[0] = 0;
    dp[1] = abs(h[1] - h[0]);

    for(int i = 2; i < N; i++) {
        // 1つ前の点からのコスト
        long long cost_1 = abs(h[i] - h[i - 1]);
        //2つ前の点からのコスト
        long long cost_2 = abs(h[i] - h[i - 2]);

        // 1つ前の辺から来た場合の、始点からの最小コスト
        long long dp_1 = dp[i - 1] + cost_1;
        // 2つ前の辺から来た場合の、始点からの最小コスト
        long long dp_2 = dp[i - 2] + cost_2;

        // 始点からの最小コスト
        dp[i] = min(dp_1, dp_2);
    }

    cout << dp[N - 1] << endl;
}
