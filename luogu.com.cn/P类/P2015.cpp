#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << '\n';
#define IAK std::ios::sync_with_stdio(false);
#define IOI std::cin.tie(nullptr)

using namespace std;
using pii = pair<int, int>;

/**
 * @File: P2015
 * @Author: wzy
 * @Date: 2026-06-07 19:54
 */

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<vector<pii>> g(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    vector a(n + 1, 0);
    vector sz(n + 1, 0);
    vector dp(n + 1, vector(q + 2, 0));
    auto dfs = [&](auto&& self, int u, int fa) -> void {
        sz[u] = 1;
        dp[u][1] = a[u];
        for (auto [v, w] : g[u]) {
            if (v == fa)
                continue;
            a[v] = w;
            self(self, v, u);
            const int max_j = min(q + 1, sz[u] + sz[v]);
            for (int j = max_j; j >= 1; j--) {
                const int max_k = min(j - 1, sz[v]);
                const int min_k = max(0, j - sz[u]);
                for (int k = min_k; k <= max_k; k++) {
                    dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[v][k] - w);
                }
            }
        }
    };
    dfs(dfs, 1, 0);
    cout << dp[1][q + 1];
}

int main()
{
    IAK IOI;
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}