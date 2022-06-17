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
        if(par[x] == -1) {
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
        if(x == y) {
            return false;
        }

        // union by size (y側のサイズが小さくなるようにする)
        if(siz[x] < siz[y]) {
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

int main() {
    int N, M;
    cin >> N >> M;

    UnionFind uf(N);

    for(int i = 0; i < M; i++) {
        // 辺abで接続されているため、aとbは同じグループに属する
        int a, b;
        cin >> a >> b;
        uf.unite(a, b);
    }

    // 集計
    int res = 0;
    for(int x = 0; x < N; x++) {
        // xとxの根が等しければ、xは根である
        // また、根の数とグループの数は等しい
        if(uf.root(x) == x) {
            res += 1;
        }
    }

    cout << res << endl;
}