#include <iostream>
#include <vector>
using namespace std;

// 入力:
//  整数N
//  整数v
//  N個の整数a[0], a[1], ..., a[N-1]
//
// 出力:
//  a[i] = vとなるデータが存在する場合、そのインデックスiを出力
//  存在しない場合、-1を出力
int main() {
    int N, v;
    cin >> N >> v;

    vector<int> a(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }

    // 線形探索
    int found_id = -1;
    for(int i = 0; i < N; i++) {
        if(a[i] == v) {
            // idを記録する
            found_id = i;
            break;
        }
    }

    cout << found_id << endl;
}