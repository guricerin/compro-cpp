#include "../common.hpp"
#include "graph_unit.hpp"

/// プリム法
/// 最小全域木のコストと、それらを構成する辺集合を求める
/// O(E log V)
pair<i64, Vertex> minimum_spanning_tree(const Graph& g, int start = 0) {
    i64 total_cost = 0;
    Vertex V;
    vector<bool> visited(g.size(), false);

    priority_queue<Edge, vector<Edge>, greater<Edge>> que;
    que.push(Edge(start, start, 0));
    while (!que.empty()) {
        const auto e = que.top();
        que.pop();
        if (visited[e.to]) continue;

        visited[e.to] = true;
        V.push_back(e);
        total_cost += e.cost;
        for (const auto& n : g[e.to]) {
            if (!visited[n.to]) {
                que.push(n);
            }
        }
    }
    return make_pair(total_cost, V);
}
