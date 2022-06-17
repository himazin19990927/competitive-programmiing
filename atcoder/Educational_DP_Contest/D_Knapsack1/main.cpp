#include <iostream>
#include <limits>
#include <vector>
using namespace std;

template <class T> void chmax(T &a, T b) {
    if(a < b) {
        a = b;
    }
}

int main() {
    int N, W;
    cin >> N >> W;

    vector<long long> w(N), v(N);
    for(int i = 0; i < N; i++) {
        cin >> w[i] >> v[i];
    }

    // DPテーブル
    vector<vector<long long>> dp(N + 1, vector<long long>(W + 1, 0));
    dp[0][0] = 0;

    // DPループ
    for(int i = 0; i < N; i++) {
        for(int w_until = 0; w_until < W; w_until++) {
            // 品物iを持ち帰らない場合
            chmax(dp[i + 1][w_until], dp[i][w_until]);

            // 品物iを持ち帰る場合
            if(w_until + w[i] <= W) {
                chmax(dp[i + 1][w_until + w[i]], dp[i][w_until] + v[i]);
            }
        }
    }

    // N個までの品物を選んだときの価値の最大値を求める
    long long value_max = 0;
    for(int i = 1; i <= W; i++) {
        chmax(value_max, dp[N][i]);
    }

    cout << value_max << endl;
}