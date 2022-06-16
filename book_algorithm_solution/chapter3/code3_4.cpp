#include <climits>
#include <iostream>
#include <vector>
using namespace std;

// 入力:
//  整数N, 整数K
//  N個の整数a[0], a[1], ..., a[N-1]
//  N個の整数b[0], b[1], ..., b[N-1]
//
// 出力:
//  a[i]とa[j]を1個ずつ選んだとき、
//  a[i] + [j] >= Kの最小値
int main() {
    int N, K;
    cin >> N >> K;

    vector<int> a(N), b(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < N; i++) {
        cin >> b[i];
    }

    // 線形探索
    int min_value = INT_MAX;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            // 和がK未満の場合は捨てる
            if(a[i] + b[j] < K) {
                continue;
            }

            // 最小値を更新
            if(a[i] + b[j] < min_value) {
                min_value = a[i] + b[j];
            }
        }
    }

    cout << min_value << endl;
}