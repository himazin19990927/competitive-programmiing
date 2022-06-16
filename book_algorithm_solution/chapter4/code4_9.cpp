#include <iostream>
#include <vector>
using namespace std;

bool func(int i, int w, const vector<int> &a) {
    // ベースケース
    if(i == 0) {
        return w == 0;
    }

    // a[i - 1]を選ばない場合
    if(func(i - 1, w, a)) {
        return true;
    }

    // a[i-1]を選ぶ場合
    if(func(i - 1, w - a[i - 1], a)) {
        return true;
    }

    // どちらもfalseの場合はfalse
    return false;
}

// 入力:
//  整数N, 整数W
//  N個の整数a[0], a[1], ..., a[N-1]
//
// 出力:
//  a[i]の中から何個かの整数を選んで、総和をWとすることが出来るかどうか
int main() {
    int N, W;
    cin >> N >> W;

    vector<int> a(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }

    if(func(N, W, a)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}