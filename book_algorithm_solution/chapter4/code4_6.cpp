
#include <iostream>

using namespace std;

// フィボナッチ数列のn番目の値を求める
int fibonacci(int N) {
    cout << "fibonacci(" << N << ") を呼び出しました" << endl;

    // ベースケース
    if(N == 0) {
        return 0;
    } else if(N == 1) {
        return 1;
    }

    int result = fibonacci(N - 1) + fibonacci(N - 2);
    cout << "fibonacci(" << N << ") = " << result << endl;

    return result;
}

int main() {
    int N;
    cin >> N;

    fibonacci(N);
}