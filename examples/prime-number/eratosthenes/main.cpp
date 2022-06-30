#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// 1以上n以下の値が素数かどうかを返す
vector<bool> eratosthenes(int n) {
    // is_prime[i] == trueのとき 2 * i + 1が素数
    vector<bool> is_prime(n + 1, true);

    // 1は素数ではない
    is_prime[0] = false;
    is_prime[1] = false;

    // i <= sqrt(n)までのiの倍数を除去すれば良い
    // (i > sqrt(n)のiについて
    // i * 1, i * 2, .., i * (i -1)はすでに除去されているから)
    const int max = (int)sqrt(n);
    for (int i = 2; i <= max; i++) {
        // すでに素数でない事がわかっている場合はスキップ
        if (!is_prime[i]) {
            continue;
        }

        // iの倍数は素数ではない
        for (int j = i * 2; j <= n; j += i) {
            is_prime[j] = false;
        }
    }

    return is_prime;
}

int main() {
    int n;
    cin >> n;

    vector<bool> is_prime = eratosthenes(n);
    for (int i = 0; i <= n; i++) {
        if (is_prime[i]) {
            cout << i << endl;
        }
    }
}