#include <iostream>
#include <vector>
using namespace std;

// https://atcoder.jp/contests/typical90/tasks/typical90_d

int main() {
    int H, W;
    cin >> H >> W;

    vector<vector<int>> A(H, vector<int>(W));
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    vector<int> H_sum(H), W_sum(W);
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            H_sum[i] += A[i][j];
            W_sum[j] += A[i][j];
        }
    }

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            int s = H_sum[i] + W_sum[j] - A[i][j];

            cout << s << " ";
        }
        cout << endl;
    }
}