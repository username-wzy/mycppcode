#include<bits/stdc++.h>
#define ll long long

using namespace std;

int dp[505][505];

void solve() {
    int p, f, c;
    cin >> p >> f >> c;
    vector<int> a(f + 1);
    for (int i = 1; i <= f; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= p; i++) {
        for (int j = 1; j <= p; j++) {
            dp[i][j] = 1e9;
        }
        dp[i][i] = 0;
    }
    for (int i = 1; i <= c; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dp[u][v] = w;
        dp[v][u] = w;
    }
    for (int k = 1; k <= p; k++) {
        for (int i = 1; i <= p; i++) {
            for (int j = 1; j <= p; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    int ans = 0, mi = 1e9;
    for (int i = 1; i <= p; i++) {
        int sum = 0;
        for (int j = 1; j <= f; j++) {
            sum += dp[i][a[j]];
        }
        if (sum < mi) {
            mi = sum;
            ans = i;
        }
    }
    cout << ans << "\n";
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