#include <iostream>
#include <limits>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

// https://atcoder.jp/contests/typical90/tasks/typical90_c

using Graph = vector<vector<int>>;

// 与えられた点から最も遠い点を探して(点, 距離)の形式で求める
pair<int, int> search_farthest(const Graph &G, int start) {
    vector<int> d(G.size(), -1);
    stack<int> next_v;
    d[start] = 0;
    next_v.push(start);

    int farthest_v = 0;
    while(!next_v.empty()) {
        int from = next_v.top();
        next_v.pop();

        for(auto to : G[from]) {
            if(d[to] != -1) {
                // 探索済みの場合はスキップ
                continue;
            }

            d[to] = d[from] + 1;

            if(d[to] > d[farthest_v]) {
                farthest_v = to;
            }

            next_v.push(to);
        }
    }

    return {farthest_v, d[farthest_v]};
}

int main() {
    int N;
    cin >> N;

    Graph G(N);
    for(int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        G[a - 1].push_back(b - 1);
        G[b - 1].push_back(a - 1);
    }

    // 点0から最も遠い場所を探す
    auto w_res = search_farthest(G, 0);
    int w_id = w_res.first;

    // 点wから最も遠い点を探す
    auto v_res = search_farthest(G, w_id);

    // 点wから最も離れた点vの間に道を作れば、最長のループとなる
    auto result = v_res.second + 1;

    cout << result << endl;
}