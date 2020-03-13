#include "../common.hpp"

/// O(log x)
template <class T>
T gcd(T x, T y) {
    return y == 0 ? x : gcd(y, x % y);
}

/// O(log x)
template <class T>
T lcm(T x, T y) {
    return x / gcd(x, y) * y;
}

/// 拡張ユークリッドの互助法: https://qiita.com/drken/items/b97ff231e43bce50199a
/// ax + by = gcd(a,b)を満たす(x,y)
/// O(log a)
/// https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E
template <class T>
T ext_gcd(T a, T b, T& x, T& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    auto d = ext_gcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

//---------------------------------------------------------------------------------------------------

// https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_C
signed main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, 0, N) {
        cin >> A[i];
    }
    auto ans = A[0];
    rep(i, 1, N) {
        ans = lcm(ans, A[i]);
    }
    cout << ans << "\n";
}
