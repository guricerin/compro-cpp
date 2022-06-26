#include "../common.hpp"

void topological_inner(const vector<vector<int>>& graph, vector<bool>& seen, vector<int>& res, int v) {
    seen[v] = true;
    for (auto u : graph[v]) {
        if (seen[u]) {
            continue;
        }
        // 頂点vからたどれる頂点は必ずres内でvより先頭に来ることになる。
        // -> 呼び出し元で逆順にすることでトポロジカルソートとなる。
        topological_inner(graph, seen, res, u);
    }
    res.push_back(v);
}

// トポロジカルソート
// 有向非巡回グラフ（サイクルをもたない有向グラフ）に対して、各頂点を辺の向きに沿うように順序付けて並び替える。
// O(VlogV + E)
vector<int> topological_sort(vector<vector<int>>& graph) {
    vector<int> res;
    const int n = graph.size();
    auto seen = vector<bool>(n, false);
    rep(i, 0, n) {
        sort(all(graph[i]));
    }
    rep(v, 0, n) {
        if (seen[v]) {
            continue;
        }
        topological_inner(graph, seen, res, v);
    }

    reverse(all(res));
    return res;
}
