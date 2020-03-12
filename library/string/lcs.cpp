#include "../common.hpp"

/// 最小共通部分列: longest common subsequence
/// O(|S||T|)
int lcs(const string& s, const string& t) {
    int slen = s.size(), tlen = t.size();
    vector<vector<int>> dp(slen + 5, vector<int>(tlen + 5, 0));

    rep(i, 0, slen) rep(j, 0, tlen) {
        if (s[i] == t[j]) {
            chmax(dp[i + 1][j + 1], dp[i][j] + 1);
        }
        chmax(dp[i + 1][j + 1], dp[i + 1][j]);
        chmax(dp[i + 1][j + 1], dp[i][j + 1]);
    }

    return dp[slen][tlen];
}

// https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_10_C
signed main() {
    int n;
    cin >> n;
    rep(i, 0, n) {
        string s, t;
        cin >> s >> t;
        cout << lcs(s, t) << "\n";
    }
}
