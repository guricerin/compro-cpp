#include "../common.hpp"

/// X^n mod m
/// 二分累乗法により、O(log n)
template <class T>
T modpow(T x, T n, const T mod) {
    T res = 1;
    while (n > 0) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >> 1;
    }
    return res;
}

//---------------------------------------------------------------------------------------------------

// https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B
signed main() {
    i64 m, n;
    cin >> m >> n;
    cout << modpow(m, n, (i64)(1e9 + 7)) << "\n";
}
