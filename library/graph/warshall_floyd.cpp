#include "../common.hpp"

/// 隣接行列の全点間最短経路
/// 到達できない要素にはinfが格納される
/// ある頂点vからv自身への最短路が負ならば、負閉路が存在する
/// O(V^3)
template <class T>
void warshall_floyd(vector<vector<T>>& mat, const T inf) {
    const auto len           = mat.size();
    rep(i, 0, len) mat[i][i] = 0;
    rep(k, 0, len) rep(i, 0, len) rep(j, 0, len) {
        if (mat[i][k] == inf || mat[k][j] == inf) continue;
        chmin(mat[i][j], mat[i][k] + mat[k][j]);
    }
}

//---------------------------------------------------------------------------------------------------

// https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C
signed main() {
    int V, E;
    cin >> V >> E;
    const auto inf = numeric_limits<i64>::max();
    vector<vector<i64>> mat(V, vector<i64>(V, inf));
    rep(i, 0, E) {
        int u, v, w;
        cin >> u >> v >> w;
        mat[u][v] = w;
    }

    warshall_floyd(mat, inf);
    rep(i, 0, V) {
        if (mat[i][i] < 0) {
            cout << "NEGATIVE CYCLE\n";
            return 0;
        }
    }

    rep(i, 0, V) rep(j, 0, V) {
        auto w = mat[i][j];
        if (w == inf)
            cout << "INF";
        else
            cout << w;
        cout << (j == V - 1 ? "\n" : " ");
    }
}
