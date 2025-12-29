#include<bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int n, m, maxn = 0;
    cin >> n >> m;
    vector<int> a(m + 10), dp(n + 10), b(n + 10);
    for (int i = 1; i <= m; i++) {cin >> a[i];maxn = max(maxn, a[i]);}
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        dp[i] = INT_MIN;
    }
    dp[1] = b[1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i - a[j] > 0) {
                int k = i - a[j];
                dp[i] = max(dp[i], dp[k] + b[i]);
            }
        }
    }
    int ans = -1e9;
    for (int i = 0; i < maxn; i++) {
        ans = max(ans, dp[n - i]);
    }
    cout << ans;
}

signed main() {
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