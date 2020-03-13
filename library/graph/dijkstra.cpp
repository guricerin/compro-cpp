#include "../common.hpp"
#include "graph_unit.hpp"

/// 負辺のない単一始点最短経路
/// O(E log V)
vector<i64> dijkstra(const Graph& g, int start) {
    const auto inf = numeric_limits<i64>::max();
    vector<i64> dist(g.size(), inf);

    using Pi = pair<i64, int>;
    priority_queue<Pi, vector<Pi>, greater<Pi>> que; // cost, id
    dist[start] = 0;
    que.push(make_pair(0, 0));
    while (!que.empty()) {
        const auto e    = que.top();
        const auto cost = e.first;
        const auto from = e.second;
        que.pop();
        if (dist[from] < cost) continue;

        for (const auto& e : g[from]) {
            const auto next_cost = e.cost + cost;
            if (chmin(dist[e.to], next_cost)) {
                que.push(make_pair(next_cost, e.to));
            }
        }
    }

    return dist;
}

//---------------------------------------------------------------------------------------------------

// https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/12/ALDS1_12_C
signed main() {
    int N;
    cin >> N;
    Graph G(N);
    rep(i, 0, N) {
        int u, k;
        cin >> u >> k;
        rep(j, 0, k) {
            int v, c;
            cin >> v >> c;
            connect(G, u, v, c);
        }
    }
    auto dist = dijkstra(G, 0);
    rep(i, 0, N) {
        cout << i << " " << dist[i] << "\n";
    }
}
