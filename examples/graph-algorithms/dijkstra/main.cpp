#include <iostream>
#include <limits>
#include <vector>
using namespace std;

const long long INF = numeric_limits<long long>::max();

// 辺を表す型
struct Edge {
    int to;      // 隣接頂点番号
    long long w; // 重み
    Edge(int to, long long w) : to(to), w(w) {}
};

// 重み付きグラフを表す型
using Graph = vector<vector<Edge>>;

// 緩和処理
template <class T> bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }

    return false;
}

int main() {
    // 頂点数、辺数、始点
    int N, M, s;
    cin >> N >> M >> s;

    // グラフ
    Graph G(N);
    for(int i = 0; i < M; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        G[a].push_back(Edge(b, w));
    }

    // ダイクストラ法
    vector<bool> used(N, false);
    vector<long long> dist(N, INF);
    dist[s] = 0;
    for(int iter = 0; iter < N; iter++) {
        // 使用済みでない頂点のうち、dist値が最小の頂点を探す
        long long min_dist = INF;
        int min_v = -1;
        for(int v = 0; v < N; v++) {
            if(!used[v] && dist[v] < min_dist) {
                min_dist = dist[v];
                min_v = v;
            }
        }

        // もし、そのような点が見つからなければ終了する
        if(min_v == -1) {
            break;
        }

        // min_vを始点とした確変を緩和する
        for(auto e : G[min_v]) {
            chmin(dist[e.to], dist[min_v] + e.w);
        }

        used[min_v] = true;
    }

    // 結果出力
    for(int v = 0; v < N; v++) {
        if(dist[v] < INF) {
            cout << dist[v] << endl;
        } else {
            cout << "INF" << endl;
        }
    }
}