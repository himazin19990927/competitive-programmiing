#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

// 深さ優先探索
void dfs(const Graph &G, int v, vector<bool> &seen) {
    seen[v] = true; // vを訪問済みにする

    // vから行ける拡張点next_vについて
    for(auto next_v : G[v]) {
        if(seen[next_v]) {
            continue; // next_vが訪問済みであれば探索しない
        }

        dfs(G, next_v, seen);
    }
}

int main() {
    // 頂点数と辺数
    int N, M;
    cin >> N >> M;

    // グラフ入力受け取り(有向グラフを想定)
    Graph G(N);
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    // 探索
    vector<bool> seen(N, false);
    for(int v = 0; v < N; v++) {
        if(seen[v]) {
            // 既に訪問済みなら探索しない
            continue;
        }
        dfs(G, v, seen);
    }
}