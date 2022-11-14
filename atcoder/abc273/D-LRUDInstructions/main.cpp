#include <bits/stdc++.h>
using namespace std;

const int IINF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr int INF = sizeof(int) == sizeof(long long) ? LINF : IINF;
const double eps = 1e-15;

int64_t coordinate_to_key(int64_t r, int64_t c, int64_t W) {
    return r * W + c;
}

int main() {
    int64_t H, W, r_player, c_player;
    cin >> H >> W >> r_player >> c_player;
    r_player -= 1;
    c_player -= 1;

    // board[r][c]に壁があるかどうか(trueで壁があるため、移動不可)
    set<int64_t> board;
    int64_t N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        int64_t ri, ci;
        cin >> ri >> ci;
        board.insert(coordinate_to_key(ri - 1, ci - 1, W));
    }

    int64_t Q;
    cin >> Q;
    for(int i = 0; i < Q; i++) {
        char di;
        int64_t li;
        cin >> di >> li;

        for(int l = 0; l < li; l++) {
            int64_t r_dest = r_player;
            int64_t c_dest = c_player;
            switch(di) {
            case 'L':
                c_dest -= 1;
                break;
            case 'R':
                c_dest += 1;
                break;
            case 'U':
                r_dest -= 1;
                break;
            case 'D':
                r_dest += 1;
                break;
            default:
                break;
            }

            if(r_dest < 0 || H <= r_dest || c_dest < 0 || W <= c_dest) {
                break;
            }

            if(board.find(coordinate_to_key(r_dest, c_dest, W)) !=
               board.end()) {
                break;
            }

            r_player = r_dest;
            c_player = c_dest;
        }

        cout << r_player + 1 << " " << c_player + 1 << endl;
    }
}