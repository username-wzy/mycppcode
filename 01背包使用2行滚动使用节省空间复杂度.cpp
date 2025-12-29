#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, W;
    cin >> n >> W;
    vector<int> v(105), w(105);
    vector<vector<int>> dp(2, vector<int> (105));
    for (int i = 1; i <= n; ++i) {
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            if (j < w[i]) {
                dp[1][j] = dp[0][j];
            } else {
                dp[1][j] = max(dp[0][j], v[i] + dp[0][j - w[i]]);
            }
        }
        for (int j = 0; j <= W; j++) dp[0][j] = dp[1][j];
    }
    cout << dp[1][W];
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