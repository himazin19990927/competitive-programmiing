#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

void dfs(const Graph &G, int v, vector<bool> &seen, vector<int> &order) {
    seen[v] = true;
    for(auto next_v : G[v]) {
        if(seen[next_v]) {
            // すでに訪問済みなら探索しない
            continue;
        }
        dfs(G, next_v, seen, order);
    }

    // v-outを記録する
    order.push_back(v);
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
    vector<bool> seen(N, false); // 初期条件では全頂点が未訪問
    vector<int> order;           // トポロジカルソート順
    for(int v = 0; v < N; v++) {
        if(seen[v]) {
            continue;
        }
        dfs(G, v, seen, order);
    }

    reverse(order.begin(), order.end()); // 逆順にする

    // 出力
    for(auto v : order) {
        cout << v << " -> ";
    }
    cout << endl;
}