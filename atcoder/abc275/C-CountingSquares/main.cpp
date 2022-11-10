#include <bits/stdc++.h>
using namespace std;

const int IINF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr int INF = sizeof(int) == sizeof(long long) ? LINF : IINF;
const double eps = 1e-15;

int main() {
    vector<vector<bool>> board(vector<vector<bool>>(9, vector<bool>(9)));
    for(int i = 0; i < 9; i++) {
        string s;
        cin >> s;

        for(int j = 0; j < 9; j++) {
            if(s[j] == '#') {

                board[i][j] = true;
            } else {

                board[i][j] = false;
            }
        }
    }

    int count = 0;

    for(int ay = 0; ay < 9; ay++) {
        for(int ax = 0; ax < 9; ax++) {
            if(!board[ay][ax]) {
                continue;
            }

            for(int by = 0; by < 9; by++) {
                for(int bx = 0; bx < 9; bx++) {
                    if(ay == by && ax == bx) {
                        continue;
                    }

                    if(!board[by][bx]) {
                        continue;
                    }

                    int delta_y = by - ay;
                    int delta_x = bx - ax;

                    int cy = ay + delta_x;
                    int cx = ax - delta_y;

                    if(cy < 0 || 9 <= cy || cx < 0 || 9 <= cx) {
                        continue;
                    }

                    if(!board[cy][cx]) {
                        continue;
                    }

                    int dy = cy + delta_y;
                    int dx = cx + delta_x;

                    if(dy < 0 || 9 <= dy || dx < 0 || 9 <= dx) {
                        continue;
                    }

                    if(!board[dy][dx]) {
                        continue;
                    }

                    count += 1;
                }
            }
        }
    }

    cout << count / 4 << endl;
}