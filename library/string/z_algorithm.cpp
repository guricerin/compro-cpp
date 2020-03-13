#include "../common.hpp"

/// 最長共通接頭辞
/// 文字列Sの左からi番目について、SとS[i..|S|]が何文字が一致しているかを処理
/// O(|S|)
namespace z_algorithm {

vector<int> run(const string& s) {
    const int len = s.size();
    vector<int> prefix(len);
    for (int i = 1, j = 0; i < len; i++) {
        if (i + prefix[i - j] < j + prefix[j]) {
            prefix[i] = prefix[i - j];
        } else {
            int k = max(0, j + prefix[j] - i);
            while (i + k < len && s[k] == s[i + k]) {
                k++;
            }
            prefix[i] = k;
            j         = i;
        }
    }
    prefix[0] = len;
    return prefix;
}

/// Tと一致する部分についてのSの左端の位置
vector<int> search(const string& s, const string& t) {
    const auto zs  = run(t + s);
    const int tlen = t.size();
    vector<int> res;
    for (int i = 0; i < (int)s.size(); i++) {
        if (zs[tlen + i] >= tlen) {
            res.push_back(i);
        }
    }
    return res;
}

}; // namespace z_algorithm

//---------------------------------------------------------------------------------------------------

// https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B
signed main() {
    string S, T;
    cin >> S >> T;

    auto ans = z_algorithm::search(S, T);
    rep(i, 0, ans.size()) {
        cout << ans[i] << "\n";
    }
}
