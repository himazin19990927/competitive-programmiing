#include <bits/stdc++.h>
using namespace std;

const int IINF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr int INF = sizeof(int) == sizeof(long long) ? LINF : IINF;
const double eps = 1e-15;

int main() {
    int H, W;
    cin >> H >> W;

    vector<vector<char>> C(H, vector<char>(W));
    for(int i = 0; i < H; i++) {
        string s;
        cin >> s;

        for(int j = 0; j < W; ++j) {
            C[i][j] = s[j];
        }
    }

    vector<int> X(W, 0);
    for(int w = 0; w < W; w++) {
        for(int h = 0; h < H; h++) {
            if(C[h][w] == '#') {
                X[w] += 1;
            }
        }
    }

    for(int w = 0; w < W; w++) {
        if(w != 0) {
            cout << " ";
        }

        cout << X[w];
    }
    cout << endl;
}