#include <iostream>
#include <limits>
#include <vector>
using namespace std;

template <class T> void chmin(T &a, T b) {
    if(a > b) {
        a = b;
    }
}

int main() {
    int N, W;
    cin >> N >> W;

    vector<long long> ws(N), vs(N);
    for(int i = 0; i < N; i++) {
        cin >> ws[i] >> vs[i];
    }

    // 価値の総和
    long long value_sum = 0;
    for(int i = 0; i < N; i++) {
        value_sum += vs[i];
    }

    // DPテーブル
    vector<vector<long long>> dp(
        N + 1, vector<long long>(value_sum + 1, 1000000000 + 1));
    dp[0][0] = 0;

    // DPループ
    // i個目までの品物で、価値がvであるとき、その重さを最小化する
    for(int i = 0; i < N; i++) {
        for(int v = 0; v <= value_sum; v++) {
            // 品物iを持ち帰らない場合
            chmin(dp[i + 1][v], dp[i][v]);

            // 品物iを持ち帰る場合
            if(v + vs[i] <= value_sum) {
                chmin(dp[i + 1][v + vs[i]], dp[i][v] + ws[i]);
            }
        }
    }

    // 重さがW以下の最も高い価値を探す
    long long max_value = -1;
    for(long long i = value_sum; i >= 0; i--) {
        if(dp[N][i] <= W) {
            max_value = i;
            break;
        }
    }

    cout << max_value << endl;
}
