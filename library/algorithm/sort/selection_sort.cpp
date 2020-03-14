#include "../../common.hpp"

/// O(n^2)
template <class T>
int selection_sort(vector<T>& vec) {
    auto len = vec.size();
    int cnt = 0;
    rep(i, 0, len) {
        auto minj = i;
        rep(j, i, len) {
            if (vec[j] < vec[minj]) {
                minj = j;
            }
        }
        if (i != minj) {
            swap(vec[i], vec[minj]);
            cnt++;
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
    auto ans = selection_sort(A);

    dump_vec(A);
    cout << ans << "\n";
}