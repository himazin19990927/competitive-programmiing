#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

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

    // 暫定的最小値
    int min_value = numeric_limits<int>::max();

    // bをソート
    sort(b.begin(), b.end());

    // bに無限大を追加
    // これを行うことで、iter = b.end()となる可能性を除外する
    b.push_back(numeric_limits<int>::max());

    // aを固定して解く
    for(int i = 0; i < N; i++) {
        // bの中で、K - a[i]以上の範囲での最小値を示すイテレータ
        auto iter = lower_bound(b.begin(), b.end(), K - a[i]);

        // イテレーターの示す値を取り出す
        int val = *iter;

        // min_valueと比較する
        if(a[i] + val < min_value) {
            min_value = a[i] + val;
        }
    }

    cout << min_value << endl;
}