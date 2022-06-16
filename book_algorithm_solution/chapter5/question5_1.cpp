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

    // DPループ
    for(int i = 0; i < N; i++) {
        // 海で泳ぐ場合(前日に海で泳いだ場合を考慮しない)
        chmax(dp[i + 1][0], dp[i][1] + a[i]);
        chmax(dp[i + 1][0], dp[i][2] + a[i]);

        // 虫取りをする場合(前日に虫取りをした場合を考慮しない)
        chmax(dp[i + 1][1], dp[i][0] + b[i]);
        chmax(dp[i + 1][1], dp[i][2] + b[i]);

        // 宿題をする場合(前日に宿題をした場合を考慮しない)
        chmax(dp[i + 1][2], dp[i][0] + c[i]);
        chmax(dp[i + 1][2], dp[i][1] + c[i]);
    }

    int res = 0;
    for(int i = 0; i < 3; i++) {
        if(dp[N][i] > res) {
            res = dp[N][i];
        }
    }

    cout << res << endl;
}
