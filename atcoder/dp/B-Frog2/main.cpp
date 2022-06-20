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
    int N, K;
    cin >> N >> K;

    vector<int> h(N);
    for(int i = 0; i < N; i++) {
        cin >> h[i];
    }

    vector<int> dp(N, numeric_limits<int>::max());
    dp[0] = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 1; j <= K; j++) {
            // h[i]からh[i + j]にジャンプするときの処理
            if(i + j < N) {
                chmin(dp[i + j], dp[i] + abs(h[i] - h[i + j]));
            }
        }
    }

    cout << dp[N - 1] << endl;
}