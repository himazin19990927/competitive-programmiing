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
    UnionFind uf(7); // {0}, {1}, {2}, {3}, {4}, {5}, {6}

    uf.unite(1, 2); // {0}, {1, 2}, {3}, {4}, {5}, {6}
    uf.unite(2, 3); // {0}, {1, 2, 3}, {4}, {5}, {6}
    uf.unite(5, 6); // {0}, {1, 2, 3}, {4}, {5, 6}

    cout << "is_same(1, 3) = " << uf.is_same(1, 3) << endl; // true
    cout << "is_same(2, 5) = " << uf.is_same(2, 5) << endl; // false

    uf.unite(1, 6); // {0}, {1, 2, 3, 4, 5, 6}, {4}
    cout << "is_same(2, 5) = " << uf.is_same(2, 5) << endl; // true
}