#include "../common.hpp"
#include "graph_unit.hpp"

/// 最小全域木のコストを求める
/// v: 頂点数
/// O(E log V)
i64 kruskal(Vertex& vertex, int v) {
    sort(all(vertex), [](const auto& x, const auto& y) { return x.cost < y.cost; });
    UnionFind uf(v);
    i64 res = 0;
    for (const auto& e : vertex) {
        if (uf.unite(e.from, e.to)) {
            res += e.cost;
        }
    }
    return res;
}
