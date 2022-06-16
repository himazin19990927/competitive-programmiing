#include <iostream>
#include <vector>
using namespace std;

// フィボナッチ数列のn番目の値を求める(メモ化)
long long fibonacci(int N, vector<long long> &memo) {
    // ベースケース
    if(N == 0) {
        return 0;
    } else if(N == 1) {
        return 1;
    }

    // メモをチェック
    if(memo[N] != -1) {
        return memo[N];
    }

    memo[N] = fibonacci(N - 1, memo) + fibonacci(N - 2, memo);

    return memo[N];
}

int main() {
    int N;
    cin >> N;

    vector<long long> memo(N + 1, -1);
    fibonacci(N, memo);

    for(int i = 2; i < N + 1; i++) {
        cout << "fibonacci[" << i << "] = " << memo[i] << endl;
    }
}
