#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long> H(N), S(N);
    for(int i = 0; i < N; i++) {
        cin >> H[i] >> S[i];
    }

    // 二分探索の上限値を求める
    // N秒後の風船の高さの最大値が、ペナルティの最大値となる
    long long M = 0;
    for(int i = 0; i < N; i++) {
        // すべての風船を割り終わるにはN秒かかる
        M = max(M, H[i] + S[i] * N);
    }

    // 二分探索
    // x = 0..Mの数字を考え、ペナルティをx以下にすることが出来るかどうかを考える
    // xの最小値が、最終的なペナルティとなる
    long long left = 0, right = M;
    while(right - left > 1) {
        long long mid = (left + right) / 2;

        // 判定する
        bool ok = true;
        vector<long long> t(N, 0); // 各風船を割るまでの制限時間
        for(int i = 0; i < N; i++) {
            // そもそもmidが初期高度より低かったらfalse
            if(mid < H[i]) {
                ok = false;
            } else {
                t[i] = (mid - H[i]) / S[i];
            }
        }

        // 制限時間が差し迫っている順にソート
        // すべてのt[i](各風船の制限時間)が、
        // その風船を割る時間i未満であることを確かめる
        sort(t.begin(), t.end());
        for(int i = 0; i < N; i++) {
            // 時間切れ発生の場合はfalse
            if(t[i] < i) {
                ok = false;
            }
        }

        if(ok) {
            right = mid;
        } else {
            left = mid;
        }
    }

    cout << right << endl;
}