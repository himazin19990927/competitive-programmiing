#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

// 二部グラフ判定
bool dfs(const Graph &G, int v, int cur, vector<int> color) {
    color[v] = cur;
    for(auto next_v : G[v]) {
        //隣接頂点が既に色確定していた場合
        if(color[next_v] != -1) {
            // 同じ色が隣接した場合は二部グラフではない
            if(color[next_v] == cur) {
                return false;
            }

            // 色が確定した場合には探索しない
            continue;
        }

        // 隣接頂点の色を変えて、再帰的に探索
        // falseが帰ってきたら、falseを返す
        if(!dfs(G, next_v, 1 - cur, color)) {
            return false;
        }
    }

    return true;
}

int main() {
    // 頂点数と変数
    int N, M;
    cin >> N >> M;

    // グラフ入力受け取り(無向グラフ)
    Graph G(N);
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // 探索
    vector<int> color(N, -1);
    bool is_bipartite = true;
    for(int v = 0; v < N; v++) {
        if(color[v] != -1) {
            // vが探索済みの場合は探索しない
            continue;
        }

        if(!dfs(G, v, 0, color)) {
            is_bipartite = false;
        }
    }

    if(is_bipartite) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}