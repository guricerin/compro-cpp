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

/// エラトステネスの篩
/// [1, n]の整数が素数であるかを返す
/// O(n loglog n)
vector<bool> sieve_of_eratosthenes(i64 n) {
    vector<bool> sieve(n + 1, true);
    sieve[0] = sieve[1] = false;

    for (i64 p = 2; p <= n; p++) {
        if (!sieve[p]) continue;

        // p以外のpの倍数をふるい落とす
        for (i64 q = p * 2; q <= n; q += p) {
            sieve[q] = false;
        }
    }

    return sieve;
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

/// メビウス関数
/// 1以外の平方数で割り切れる: 0
/// nが相異なるk個の素因数に分解されるとき: (-1)^k
/// O(√ n)
int mobius(i64 n) {
    if (n == 1) return 1;
    auto ps = prime_factors(n);
    for (auto& [p, e] : ps) {
        if (e >= 2) return 0;
    }

    if (ps.size() % 2 == 0) {
        return 1;
    } else {
        return -1;
    }
}
