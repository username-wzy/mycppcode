#include<bits/stdc++.h>
#define ll long long

using namespace std;

int dp[105][105], a[105];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = 1e9;
        }
        dp[i][i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        int u, v; 
        cin >> a[i] >> u >> v;
        if (u > 0) {dp[i][u] = 1; dp[u][i] = 1;}
        if (v > 0) {dp[i][v] = 1; dp[v][i] = 1;}
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    int ans = 1e9;
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 1; j <= n; j++) {
            sum += dp[i][j] * a[j];
        }
        ans = min(ans, sum);
    }
    cout << ans;
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