#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

// 入力: グラフGと、探索の始点s
// 出力: sから各頂点への採点路長を表す配列
vector<int> bfs(const Graph &G, int s) {
    int N = (int)G.size();   // 頂点数
    vector<int> dist(N, -1); //全頂点を未訪問に初期化
    queue<int> que;

    // 初期条件(頂点0を初期頂点とする)
    dist[s] = 0;
    que.push(s);

    // bfs開始
    while(!que.empty()) {
        int v = que.front(); // キューから先頭頂点を取り出す
        que.pop();

        // vからたどれる頂点をすべて調べる
        for(int x : G[v]) {
            // 既に発見済みの頂点は探索しない
            if(dist[x] != -1) {
                continue;
            }

            // 新たな未探索頂点vについて距離情報を更新してキューに挿入
            dist[x] = dist[v] + 1;
            que.push(x);
        }
    }

    return dist;
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

    // 頂点0を始点としたBFS
    vector<int> dist = bfs(G, 0);

    // 結果出力
    for(int v = 0; v < N; v++) {
        cout << v << ": " << dist[v] << endl;
    }
}