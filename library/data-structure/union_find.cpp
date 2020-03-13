#include "../common.hpp"

/// 素集合データ構造: Union Find Tree (Disjoint Set)
struct UnionFind {
    vector<int> _ids; // 添字iが属する集合のID

    UnionFind(int n) {
        _ids.assign(n, -1);
    }

    int root(int x) {
        const auto rx               = _ids[x];
        return rx < 0 ? x : _ids[x] = root(rx);
    }

    // 要素xとyは同じ連結成分に属するか？
    bool connected(int x, int y) {
        return root(x) == root(y);
    }

    // 要素xが属する集合の要素数
    int size(int x) {
        return -_ids[root(x)];
    }

    // 要素xとyを連結
    bool unite(int x, int y) {
        auto rx = root(x), ry = root(y);
        if (rx == ry) return false;

        if (_ids[rx] > _ids[ry]) swap(rx, ry);
        _ids[rx] += _ids[ry];
        _ids[ry] = rx;
        return true;
    }
};