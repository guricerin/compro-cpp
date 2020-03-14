#include "../../common.hpp"

/// O(n^2)
/// ただし、ある程度整列済みならO(n)
template <class T>
void insertion_sort(vector<T>& vec) {
    auto len = vec.size();
    rep(i, 1, len) {
        auto a = vec[i];
        auto j = i - 1;
        while (j >= 0 && vec[j] > a) {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = a;
        dump_vec(vec);
    }
}

signed main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, 0, N) {
        cin >> A[i];
    }
    dump_vec(A);
    insertion_sort(A);
}
