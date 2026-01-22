#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, W;
    cin >> W >> n;
    vector<int> v(1e4 + 5), w(1e4 + 5), dp(1e4 + 5);
    for (int i = 1; i <= n; ++i) {
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = w[i]; j <= W; j++) {
            dp[j] = max(dp[j], v[i] + dp[j - w[i]]);
        }
    }
    cout << dp[W];
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