#include <iostream>
using namespace std;

// 整数mとnの最大公約数を求める
int GCD(int m, int n) {
    // ベースケース
    if(n == 0) {
        return m;
    }

    return GCD(n, m % n);
}

int main() {
    int m, n;
    cin >> m >> n;

    cout << GCD(m, n) << endl;
}