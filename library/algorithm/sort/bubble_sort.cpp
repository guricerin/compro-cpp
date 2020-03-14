#include "../../common.hpp"

/// O(n^2)
/// バブルソートの交換回数は反転数または転倒数と呼ばれるもので、列の乱れの具合を表す
template <class T>
int bubble_sort(vector<T>& vec) {
    auto len = vec.size();
    int cnt = 0;     // スワップ回数
    bool flg = true; // 逆の隣接要素が存在する
    while (flg) {
        flg = false;
        for (int i = len - 1; i >= 1; i--) {
            if (vec[i] < vec[i - 1]) {
                swap(vec[i], vec[i - 1]);
                flg = true;
                cnt++;
            }
        }
    }
    return cnt;
}

signed main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, 0, N) {
        cin >> A[i];
    }

    auto ans = bubble_sort(A);
    dump_vec(A);
    cout << ans << "\n";
}
