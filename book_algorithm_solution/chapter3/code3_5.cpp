#include <climits>
#include <iostream>
#include <vector>
using namespace std;

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

    // bitは2^N通りの部分集合全体を動く
    bool exist = false;
    for(int bit = 0; bit < (1 << N); bit++) {
        // 部分集合に含まれる要素の和
        int sum = 0;
        for(int i = 0; i < N; i++) {
            // i番目の要素a[i]が部分集合に含まれているかどうか
            if(bit & (1 << i)) {
                sum += a[i];
            }
        }

        // sumがWに一致するかどうか
        if(sum == W) {
            exist = true;
        }
    }

    if(exist) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}