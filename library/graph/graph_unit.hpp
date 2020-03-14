#include "../common.hpp"

struct Edge {
    int from, to;
    i64 cost;
    Edge() {}
    Edge(int t, i64 c) : from(-1), to(t), cost(c) {}
    Edge(int f, int t, i64 c) : from(f), to(t), cost(c) {}

    bool operator<(const Edge& r) const {
        return cost < r.cost;
    }
    bool operator>(const Edge& r) const {
        return cost > r.cost;
    }
};

using Vertex = vector<Edge>;
using Graph = vector<Vertex>;

// 無向
void link(Graph& g, int from, int to, int cost = 1) {
    g[from].push_back(Edge(from, to, cost));
    g[to].push_back(Edge(to, from, cost));
    return;
}

// 有向
void connect(Graph& g, int from, int to, int cost = 1) {
    g[from].push_back(Edge(from, to, cost));
    return;
}
