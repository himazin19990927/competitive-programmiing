#include <bits/stdc++.h>
using namespace std;

static const string atcoder = "atcoder";
static const int atcoder_len = atcoder.length();

int char_to_id(char c) {
    for (int i = 0; i < atcoder_len; i++) {
        if (c == atcoder[i]) {
            return i;
        }
    }

    return -1;
}

// この解法はO(n^2)なので TLE
int main() {
    const long long mod = 1000000000 + 7;

    // 文字列Sの長さ
    int N;
    cin >> N;

    // 文字列S
    string S;
    cin >> S;

    // "atcoder"内のいずれかの文字があるインデックスを記録する
    // char_index[atcoderの何文字目][何番目のindex] = Sの何番目
    vector<vector<int>> char_index(atcoder_len);
    for (int i = 0; i < N; i++) {
        int char_id = char_to_id(S[i]);
        if (char_id != -1) {
            int remain = (atcoder_len - 1) - char_id;
            int valid_until = N - remain;
            if (i <= valid_until) {
                char_index[char_id].push_back(i);
            }
        }
    }

    // dp[atcoderの何文字目まで][何番目のindex] = 組み合わせの数
    vector<vector<int>> dp(atcoder_len);
    for (int i = 0; i < atcoder_len; i++) {
        dp[i] = vector<int>(char_index[i].size(), 0);
    }

    // 初期化
    for (int i = 0; i < dp[0].size(); i++) {
        dp[0][i] = 1;
    }

    for (int i = 1; i < atcoder_len; i++) {
        for (int j = 0; j < char_index[i].size(); j++) {
            for (int k = 0; k < char_index[i - 1].size(); k++) {
                if (char_index[i - 1][k] < char_index[i][j]) {
                    dp[i][j] += dp[i - 1][k];
                    dp[i][j] %= mod;
                }
            }
        }
    }
    long long result = 0;
    for (int i = 0; i < dp[atcoder_len - 1].size(); i++) {
        result += dp[atcoder_len - 1][i];
        result %= mod;
    }

    cout << result << endl;
}
