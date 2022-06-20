#include <cmath>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

// 未正答
int main() {
    // N桁の整数
    long long N;

    // Bの倍数
    int B;

    // 入力の数
    int K;
    cin >> N >> B >> K;

    const long long mod = pow(10, 9) + 7;

    vector<int> C(K);
    for(int i = 0; i < K; i++) {
        cin >> C[i];
    }

    // dp[上から何桁目][現時点でのBで割ったあまり] = 通り数
    vector<vector<int>> dp(N + 1, vector<int>(B, 0));
    dp[0][0] = 1;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < B; j++) {
            for(int k = 0; k < K; k++) {
                int nex = (10 * j + C[k]) % B;
                dp[i + 1][nex] += dp[i][j];
                dp[i + 1][nex] %= mod;
            }
        }
    }

    cout << dp[N][0] << endl;
}