#include "../common.hpp"

/// 平均
template <class T>
double average(const vector<T>& ls) {
    return accumulate(all(ls), 0.0) / (double)ls.size();
}

/// 分散 : データの散らばり具合
/// 各要素に対する「データの平均値からの距離の二乗」の平均値
/// 分散が0 -> データの値がすべて等しい
template <class T>
double variance(const vector<T>& ls) {
    auto ave = average(ls);
    double sum = 0;
    for (auto l : ls) {
        sum += pow(l - ave, 2);
    }
    return sum / (double)ls.size();
}

/// 標準偏差 : 分散の非負の平方根
/// 分散と比較した場合、各データの単位と一致するというメリットがある
template <class T>
double std_deviation(const vector<T>& ls) {
    auto omega = variance(ls);
    return sqrt(omega);
}

/// 共分散 : 2組の対応するデータ間での分散
/// 元のデータの大きさで値が決まるので、解釈が難しい
template <class T>
double covariance(const vector<T>& as, const vector<T>& bs) {
    assert(as.size() == bs.size());

    auto aave = average(as), bave = average(bs);
    const int n = as.size();
    double sum = 0;
    rep(i, 0, n) {
        sum += (as[i] - aave) * (bs[i] - bave);
    }
    return sum / (double)n;
}

/// 相関係数 : 2組のデータ間の線形な関係の強弱を測る指標
/// 値域は [-1,1]
/// -1に近い -> 負の相関、0に近い -> 相関なし、1に近い -> 正の相関
/// 因果関係があるかまでは測れない
/// また、直線的でない関係性がある場合、相関係数が+-1に近いとは限らない（ex. y = |x| の場合、相関係数は0となる）
template <class T>
double correlation_coefficient(const vector<T>& as, const vector<T>& bs) {
    auto covar = covariance(as, bs);
    auto asd = std_deviation(as), bsd = std_deviation(bs);
    return covar / (asd * bsd);
}

/// 中央値
template <class T>
double median(const vector<T>& ls) {
    int mid = ls.size() / 2;
    if (ls.size() & 1) {
        return ls[mid];
    } else {
        return (ls[mid - 1] + ls[mid]) / 2.0;
    }
}

/// 四分位数
template <class T>
tuple<double, double, double> quartile(const vector<T>& ls) {
    // [l,r) における中央値
    auto f = [&](int l, int r) {
        const int sz = r - l;
        if (sz & 1) {
            int mid = l + (r - l - 1) / 2;
            return (double)ls[mid];
        } else {
            int mid = l + (r - l) / 2;
            return ((double)ls[mid - 1] + (double)ls[mid]) / 2.0;
        }
    };

    const int n = ls.size();
    double m = f(0, n);
    double l, r;
    if (n & 1) {
        l = f(0, (n - 1) / 2);
        r = f((n - 1) / 2 + 1, n);
    } else {
        l = f(0, n / 2);
        r = f(n / 2, n);
    }
    return make_tuple(l, m, r);
}
