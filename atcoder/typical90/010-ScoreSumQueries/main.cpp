#include <bits/stdc++.h>
using namespace std;

int main() {
    // 生徒数N
    int N;
    cin >> N;

    // S[クラスc][学籍番号i] = クラスcの学籍番号iまでの点数の和
    vector<vector<int>> S(2, vector<int>(N + 1, 0));
    for(int i = 1; i <= N; i++) {
        int c, p;
        cin >> c >> p;

        S[0][i] = S[0][i - 1];
        S[1][i] = S[1][i - 1];
        S[c - 1][i] += p;
    }

    // 質問数Q
    int Q;
    cin >> Q;

    // 回答
    for(int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;

        int a = S[0][r] - S[0][l - 1];
        int b = S[1][r] - S[1][l - 1];

        cout << a << " " << b << endl;
    }
}