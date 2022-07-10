#include <bits/stdc++.h>
using namespace std;

const int IINF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr int INF = sizeof(int) == sizeof(long long) ? LINF : IINF;
const double eps = 1e-15;

using Graph = vector<vector<int>>;

struct Circle {
    int x;
    int y;
    int r;

    Circle() : x(0), y(0), r(0) {}
    Circle(int x, int y, int r) : x(x), y(y), r(r) {}

    bool contains(const Circle &other) {
        int dx = other.x - x;
        int dy = other.y - y;
        int D2 = dx * dx + dy * dy;

        int Rp = (r + other.r) * (r + other.r);
        int Rm = (r - other.r) * (r - other.r);

        return !(D2 > Rp || D2 < Rm);
    }

    bool on_circumference(int px, int py) {
        int dx = px - x;
        int dy = py - y;

        return dx * dx + dy * dy == r * r;
    }
};

// S-Tパスが存在するか
bool search(const Graph &G, int S, int T) {
    int N = (int)G.size();
    vector<bool> seen(N, false); // 訪問済みならfalse
    stack<int> todo;

    seen[S] = true;
    todo.push(S);

    while(!todo.empty()) {
        int v = todo.top();
        todo.pop();

        // vがTならS-Tパスが存在する
        if(v == T) {
            return true;
        }

        // vから辿れる頂点をすべて調べる
        for(int x : G[v]) {
            if(seen[x]) {
                continue;
            }

            seen[x] = true;
            todo.push(x);
        }
    }

    return false;
}

// 現在、一部のテストが通らず、不正解
int main() {
    int N;
    cin >> N;

    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    int S, T;
    vector<Circle> circles(N);
    for(int i = 0; i < N; i++) {
        int x, y, r;
        cin >> x >> y >> r;
        Circle c(x, y, r);
        circles[i] = c;

        if(c.on_circumference(sx, sy)) {
            S = i;
        }
        if(c.on_circumference(tx, ty)) {
            T = i;
        }
    }

    // グラフを作成
    Graph G(N);
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            if(circles[i].contains(circles[j])) {
                G[i].push_back(j);
                G[j].push_back(i);
            }
        }
    }

    // Sから深さ優先探索して、Tへの道が存在する場合
    if(search(G, S, T)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}