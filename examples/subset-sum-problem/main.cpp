#include <bits/stdc++.h>
using namespace std;

const int IINF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr int INF = sizeof(int) == sizeof(long long) ? LINF : IINF;
const double eps = 1e-15;

// 問題
// n 個の正の整数 a[0], a[1], ..,a[n−1], a[0], a[1], .., a[n−1] と
// 正の整数 W が与えられる。
// これらの整数から何個かの整数を選んで総和が W
// になるようにすることが可能か判定せよ。
//可能ならば "YES"と出力し、不可能ならば "NO" と出力せよ。

// 入力
// N W
// A[0] A[1] ...

int main() {
    // 整数の個数 N , 総和 W
    int N, W;

    cin >> N >> W;

    // 配列
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // dp[i: 何個目までの整数を選ぶか][j: 総和をいくつにするか]
    //  = i個目までの整数を使って、総和がjにできるかどうか
    vector<vector<bool>> dp(N + 1, vector<bool>(W + 1, false));

    // 初期条件
    // 0個目までの整数を使って総和を0にすることは可能
    dp[0][0] = true;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= W; j++) {
            // i個目の整数を使用しない場合
            // A[0], A[1], ..., A[i-1]の整数を使って、
            // 総和を j にすることができるならば
            // A[i]を使わなくても総和を j にすることができる。
            // つまり、dp[i][j] == trueである時、i個目の整数(A[i])を使用して、
            // 総和を j にすることができる
            dp[i + 1][j] = dp[i + 1][j] || dp[i][j];

            if (j >= A[i]) {
                // i個目の整数を使用する場合
                // A[0], A[1], ..., A[i-1]の整数を使って、
                // 総和を j - A[j] にすることができるならば
                // A[i]を使って総和を j にすることができる。
                // つまり、dp[i][j - A[i]] == trueであるとき、
                // i個目の整数(A[i])を使用して、 総和を j にすることができる
                dp[i + 1][j] = dp[i + 1][j] || dp[i][j - A[i]];
            }
        }
    }

    if (dp[N][W]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}