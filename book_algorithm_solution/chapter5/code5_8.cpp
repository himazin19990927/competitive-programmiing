#include <iostream>
#include <limits>
#include <string>
#include <vector>
using namespace std;

template <class T> void chmin(T &a, T b) {
    if(a > b) {
        a = b;
    }
}

int main() {
    string S, T;

    cin >> S >> T;

    // DPテーブル
    vector<vector<int>> dp(
        S.size() + 1, vector<int>(T.size() + 1, numeric_limits<int>::max()));
    // DP初期条件
    dp[0][0] = 0;

    // DPループ
    for(int i = 0; i <= S.size(); i++) {
        for(int j = 0; j <= T.size(); j++) {
            // 変更操作
            if(i > 0 && j > 0) {
                if(S[i - 1] == T[j - 1]) {
                    chmin(dp[i][j], dp[i - 1][j - 1]);
                } else {
                    chmin(dp[i][j], dp[i - 1][j - 1] + 1);
                }
            }

            // 削除操作
            if(i > 0) {
                chmin(dp[i][j], dp[i - 1][j] + 1);
            }

            // 挿入操作
            if(j > 0) {
                chmin(dp[i][j], dp[i][j - 1] + 1);
            }
        }
    }

    cout << dp[S.size()][T.size()] << endl;
}