#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long> A(N), B(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    // 答え
    long long sum = 0;
    for(int i = N - 1; i >= 0; i--) {
        // 前回までの操作回数を足す
        A[i] += sum;

        long long r = A[i] % B[i];
        long long d = 0;
        if(r != 0) {
            d = B[i] - r;
        }

        sum += d;
    }

    cout << sum << endl;
}