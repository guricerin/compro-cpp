#include "../common.hpp"

/// O(√ n)
bool is_prime(i64 n) {
    if (n <= 1) return false;
    for (i64 p = 2; p * p <= n; p++) {
        if (n % p == 0) return false;
    }
    return true;
}