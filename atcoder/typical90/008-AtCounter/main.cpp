#include <bits/stdc++.h>
using namespace std;

int main() {
    const string atcoder = "atcoder";
    const int L = (int)atcoder.length();
    const long long mod = 1000000000 + 7;

    // 文字列Sの長さ
    int N;
    cin >> N;

    // 文字列S
    string S;
    cin >> S;

    // dp[pos][atcoderの何番目]
    vector<vector<long long>> dp(N + 1, vector<long long>(L + 1, 0));
    dp[0][0] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= L; j++) {
            // Sの i 番目
            // "atcoder"の j 番目

            // i番目の文字を選ぶ場合
            if (S[i] == atcoder[j]) {
                // Sのi番目が適切であるときのみを考える
                dp[i + 1][j + 1] += dp[i][j];
                dp[i + 1][j + 1] %= mod;
            }

            // i番目の文字を選ばない場合
            dp[i + 1][j] += dp[i][j];
            dp[i + 1][j] %= mod;
        }
    }

    cout << dp[N][L] << endl;
}