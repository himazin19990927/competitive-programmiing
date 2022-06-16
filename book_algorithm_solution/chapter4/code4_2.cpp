#include <iostream>
using namespace std;

// 数列0, 1, 2, ...,Nの値の総和を求める
int sum(int N) {
    // 再帰関数を呼び出したことを報告
    cout << "sum(" << N << ") を呼び出しました" << endl;

    if(N == 0) {
        return 0;
    }

    int result = N + sum(N - 1);
    cout << N << "までの和 = " << result << endl;

    return result;
}

int main() {
    int N;
    cin >> N;

    sum(N);
}
