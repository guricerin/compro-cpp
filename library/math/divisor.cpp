#include "../common.hpp"

/// 約数列挙
/// O(√ n)
vector<i64> divisors(i64 n) {
    vector<i64> res;
    for (i64 i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res.push_back(i);
            if (i * i != n) {
                res.push_back(n / i);
            }
        }
    }
    sort(res.begin(), res.end());
    return res;
}

/// nは平方数であるか
/// 平方数: 約数が奇数個の数値
bool is_square(i64 n) {
    // √n を整数にキャストする
    // 数値誤差を回避するため、EPS = 10^-9 を足している
    const double eps = 1e-9;
    i64 sq = (i64)(sqrt(n) + eps);
    return (sq * sq) == n;
}

/// n以下の平方数の個数
i64 square_nums(i64 n) {
    const double eps = 1e-9;
    i64 sq = (i64)(sqrt(n) + eps);
    return sq;
}
