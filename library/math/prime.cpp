#include "../common.hpp"

/// O(√ n)
bool is_prime(i64 n) {
    if (n <= 1) return false;
    for (i64 p = 2; p * p <= n; p++) {
        if (n % p == 0) return false;
    }
    return true;
}

/// 素因数分解
/// O(√ n)
map<i64, i64> prime_factors(i64 n) {
    map<i64, i64> res; // factor, num
    for (i64 p = 2; p * p <= n; p++) {
        while (n % p == 0) {
            res[p]++;
            n /= p;
        }
    }
    if (n != 1) res[n] = 1;
    return res;
}

/// オイラーのφ関数: https://mathtrain.jp/phi
/// n以下の整数のうち、nと互いに素であるものの個数
/// O(√ n)
i64 eulers_phy_function(i64 n) {
    auto mp = prime_factors(n);
    f64 res = n;
    for (auto p : mp) {
        res *= 1.0 - (1.0 / p.first);
    }
    return (i64)res;
}