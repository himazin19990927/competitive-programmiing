#include <climits>
#include <iostream>
#include <vector>
using namespace std;

// choose minimum
template <class T> void chmin(T &a, T b) {
    if(a > b) {
        a = b;
    }
}

int main() {
    int N;
    cin >> N;

    vector<long long> h(N);
    for(int i = 0; i < N; i++) {
        cin >> h[i];
    }

    vector<long long> dp(N, LONG_LONG_MAX);

    dp[0] = 0;
    dp[1] = abs(h[1] - h[0]);
    for(int i = 2; i < N; i++) {
        chmin(dp[i], dp[i - 1] + abs(h[i] - h[i - 1]));
        chmin(dp[i], dp[i - 2] + abs(h[i] - h[i - 2]));
    }

    cout << dp[N - 1] << endl;
}