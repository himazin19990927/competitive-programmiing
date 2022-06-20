#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct UnionFind {
    // 各頂点の親頂点の番号
    vector<int> par;

    // 各頂点の属する根付き木の頂点数
    vector<int> siz;

    UnionFind(int n) : par(n, -1), siz(n, 1) {}

    // 頂点xの根を求める
    int root(int x) {
        if (par[x] == -1) {
            // xが根の場合はxを返す
            return x;
        } else {
            // 再帰的にxの親をたどり、根を返す
            // xの親を根とすることで、経路を圧縮する
            return par[x] = root(par[x]);
        }
    }

    // xとyが同じグループに属するかを判定
    bool is_same(int x, int y) { return root(x) == root(y); }

    // xを含むグループと、yを含むグループとを併合する
    // xとyが併合された場合はtrueを返す
    bool unite(int x, int y) {
        // x, yをそれぞれ根まで移動する
        x = root(x);
        y = root(y);

        // 既に同じグループのときは何もしない
        if (x == y) {
            return false;
        }

        // union by size (y側のサイズが小さくなるようにする)
        if (siz[x] < siz[y]) {
            swap(x, y);
        }

        // yをxの子とする
        par[y] = x;
        siz[x] += siz[y];

        return true;
    }

    // xを含むグループのサイズ
    int size(int x) { return siz[root(x)]; }
};

// 辺 e = (u, v)を{ w(e), {u, v}}で表す
using Edge = pair<int, pair<int, int>>;

int main() {
    // 入力
    int N, M; // 頂点数と辺数
    cin >> N >> M;
    vector<Edge> edges(M); // 辺集合
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = Edge(w, make_pair(u, v));
    }

    // 各辺を、辺の重みが小さい順にソートする
    // pairはデフォルトで(第1要素、第２要素)の辞書順比較
    sort(edges.begin(), edges.end());

    // クラスカル法
    long long res = 0;
    UnionFind uf(N);
    for (int i = 0; i < M; i++) {
        int w = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;

        // 頂点u, vが同じグループに所属しているならば、 uからvへのパスが存在する
        // そのため、辺(u, v)を追加するとサイクルが形成されるため、追加しない
        if (uf.is_same(u, v)) {
            continue;
        }

        // 辺(u, v)を追加する
        res += w;
        uf.unite(u, v);
    }

    cout << res << endl;
}