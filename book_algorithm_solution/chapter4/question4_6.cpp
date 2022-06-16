#include <iostream>
#include <vector>
using namespace std;

// 1: true, 0: false
int func(int i, int w, const vector<int> &a, vector<vector<int>> &memo) {
    // ベースケース
    if(i == 0) {
        if(w == 0) {
            return 1;
        } else {
            return 0;
        }
    }

    // 既に計算済みの場合、リターン
    if(memo[i][w] != -1) {
        return memo[i][w];
    }

    // a[i - 1]を選ばない場合
    if(func(i - 1, w, a, memo)) {
        memo[i][w] = 1;
        return 1;
    }

    // a[i - 1]を選ぶ場合
    if(func(i - 1, w - a[i - 1], a, memo)) {
        memo[i][w] = 1;
        return 1;
    }

    memo[i][w] = 0;
    return 0;
}

int main() {
    int N, W;
    cin >> N >> W;

    vector<int> a(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }

    // メモ
    vector<vector<int>> memo(N + 1, vector<int>(W + 1, -1));

    if(func(N, W, a, memo) == 1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}