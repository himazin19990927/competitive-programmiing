#include <iostream>
#include <vector>
using namespace std;

// 入力:
//      整数N
//  整数v
//  N個の整数a[0], a[1], ..., a[N-1]
//
// 出力:
//  a[i] = vとなるデータが存在するかどうかを"Yes" or "No"で出力
int main() {
    int N, v;
    cin >> N >> v;

    vector<int> a(N);
    for(int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    // 線形探索
    bool exist = false;
    for(int i = 0; i < N; ++i) {
        if(a[i] == v) {
            exist = true;
        }
    }

    if(exist) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
