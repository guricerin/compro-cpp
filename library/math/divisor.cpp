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
