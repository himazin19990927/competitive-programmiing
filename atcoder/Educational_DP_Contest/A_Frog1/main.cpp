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
    int N;
    cin >> N;

    vector<int> h(N);
    for(int i = 0; i < N; i++) {
        cin >> h[i];
    }

    vector<int> dp(N, numeric_limits<int>::max());
    dp[0] = 0;
    dp[1] = abs(h[1] - h[0]);

    for(int i = 2; i < N; i++) {
        chmin(dp[i], dp[i - 1] + abs(h[i - 1] - h[i]));
        chmin(dp[i], dp[i - 2] + abs(h[i - 2] - h[i]));
    }

    cout << dp[N - 1] << endl;
}