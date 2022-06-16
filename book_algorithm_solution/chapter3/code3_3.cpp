#include <climits>
#include <iostream>
#include <vector>
using namespace std;

// 入力:
//  整数N
//  N個の整数a[0], a[1], ..., a[N-1]
// 
// 出力:
//  与えられた整数a[i]の最小値
int main() {
    int N;
    cin >> N;

    vector<int> a(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }


    // 最小値を線形探索
    int min_value = INT_MAX;
    for(int i = 0; i < N; i++) {
        if(a[i] < min_value) {
            min_value = a[i];
        }
    }

    cout << min_value << endl;
}