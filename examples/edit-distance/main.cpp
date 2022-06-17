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

// 入力S, Tの編集距離を求める
int main() {
    // 入力
    string S, T;
    cin >> S >> T;

    // DPテーブル
    // dp[i][j]はS[0, i]と、T[0, j]の編集距離
    // ただし、
    // S[0, i]はS[0]からS[i-1]までの文字列
    // S = "abcd"のとき
    // S[0, 0] = "", S[0, 1] = "a", S[0, 2] = "ab", S[0, 3] = "abc"
    vector<vector<int>> dp(
        S.size() + 1, vector<int>(T.size() + 1, numeric_limits<int>::max()));

    // DP初期条件
    // S[0, 0] = ""とT[0, 0]の編集距離は0
    dp[0][0] = 0;

    // DPループ
    for(int i = 0; i <= S.size(); i++) {
        for(int j = 0; j <= T.size(); j++) {

            // 変更操作
            if(i > 0 && j > 0) {
                if(S[i - 1] == T[j - 1]) {
                    // S[i-1]とT[j-1]が等しい
                    // つまり、S[0, i]とS[0, j]の最後の文字が等しい場合
                    // S[0, i]とT[0, j]の編集距離は
                    // S[0, i-1]とT[0, j-1]の編集距離と等しい
                    chmin(dp[i][j], dp[i - 1][j - 1]);

                } else {
                    // S[i-1]とT[j-1]が異なる場合,
                    // S[0, i]の最後の文字を変更する
                    // そのため、S[0, i]とT[0, j]の編集距離は
                    // S[0, i-1]とT[0, j-1]の編集距離に1を加算したものとなる
                    chmin(dp[i][j], dp[i - 1][j - 1] + 1);
                }
            }

            // 削除操作(S[i-1]の文字を削除)
            if(i > 0) {
                // S[i-1]の文字を削除するので、
                // S[0, i]とT[0, j]の編集距離は
                // S[0, i-1]とT[0, j]の編集距離に1を加算したものとなる
                chmin(dp[i][j], dp[i - 1][j] + 1);
            }

            // 挿入操作(T[j-1]の文字を削除)
            if(j > 0) {
                // T[j-1]の文字を削除するので、
                // S[0, i]とT[0, j]の編集距離は
                // S[0, i]とT[0, j-1]の編集距離に1を加算したものとなる
                chmin(dp[i][j], dp[i][j - 1] + 1);
            }
        }
    }

    // SとTの編集距離の出力
    cout << dp[S.size()][T.size()] << endl;
}