#include <bits/stdc++.h>
using namespace std;

int main() {
    // クラスの数
    int N;
    cin >> N;

    // A[i]はクラスiの対象とするレーティング
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // 生徒の数
    int Q;
    cin >> Q;

    // B[i]は生徒iのレーティング
    vector<int> B(Q);
    for (int i = 0; i < Q; i++) {
        cin >> B[i];
    }

    // クラスのレーティングをソート
    sort(A.begin(), A.end());

    // 各生徒に対して最小の不満足度を足していく
    for (int i = 0; i < Q; i++) {
        // 二分探索
        int left = 0;
        int right = N;
        while (right - left > 1) {
            int mid = left + (right - left) / 2;

            if (A[mid] <= B[i]) {
                left = mid;
            } else {
                right = mid;
            }
        }

        // 不満足度
        int cost = min(abs(B[i] - A[left]), abs(B[i] - A[right]));
        cout << cost << endl;
    }
}