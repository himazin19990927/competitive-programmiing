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
    int N;
    cin >> N;

    vector<int> a(N), b(N), c(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    // DPテーブル
    vector<vector<int>> dp(N + 1, vector<int>(3, 0));
    for(int i = 0; i < 3; i++) {
        dp[0][i] = 0;
    }

    // DPループ
    for(int i = 1; i <= N; i++) {
        // 行動A(0)をしたときのi+1日目の幸福度
        chmax(dp[i][0], dp[i - 1][1] + a[i - 1]);
        chmax(dp[i][0], dp[i - 1][2] + a[i - 1]);

        // 行動B(1)をしたときのi+1日目の幸福度
        chmax(dp[i][1], dp[i - 1][0] + b[i - 1]);
        chmax(dp[i][1], dp[i - 1][2] + b[i - 1]);

        // 行動C(2)をしたときのi+1日目の幸福度
        chmax(dp[i][2], dp[i - 1][0] + c[i - 1]);
        chmax(dp[i][2], dp[i - 1][1] + c[i - 1]);
    }

    int max = 0;
    for(int i = 0; i < 3; i++) {
        chmax(max, dp[N][i]);
    }

    cout << max << endl;
}