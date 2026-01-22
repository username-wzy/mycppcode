#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, W;
    cin >> n >> W;
    vector<int> v(105), w(105);
    vector<vector<int>> dp(105, vector<int> (105));
    for (int i = 1; i <= n; ++i) {
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            if (j < w[i]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], v[i] + dp[i - 1][j - w[i]]);
            }
        }
    }
    cout << dp[n][W] << '\n';
    set<int> st;
    for (int i = n; i >= 1; i--) {
        if (dp[i][W] != dp[i - 1][W]) {
            st.insert(i);
            W -= w[i];
        }
    }
    for (auto p: st) {
        cout << p << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // freopen("xxx.in", "r", stdin);
    // freopen("xxx.out", "w", stdout);

    int T = 1; // cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}