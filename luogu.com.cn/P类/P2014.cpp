#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << '\n';
#define IAK std::ios::sync_with_stdio(false);
#define IOI std::cin.tie(nullptr)

using namespace std;

/**
 * @File: P2014
 * @Author: wzy
 * @Date: 2026-06-07 19:11
 */

void solve()
{
    int n, m;
    cin >> n >> m;
    vector a(n + 1, 0);
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k >> a[i];
        g[k].push_back(i);
        g[i].push_back(k);
    }
    vector dp(n + 1, vector(m + 2, 0));
    vector siz(n + 1, 0);

    auto dfs = [&](auto&& self, int u, int fa) -> void {
        dp[u][1] = a[u];
        siz[u] = 1;

        for (int v : g[u]) {
            if (v == fa)
                continue;
            self(self, v, u);
            const int max_j = min(m + 1, siz[u] + siz[v]);
            for (int j = max_j; j >= 1; j--) {
                const int max_k = min(j - 1, siz[v]);
                const int min_k = max(0, j - siz[u]);
                for (int k = min_k; k <= max_k; k++) {
                    dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[v][k]);
                }
            }
            siz[u] += siz[v];
        }
    };

    dfs(dfs, 0, -1);
    cout << dp[0][m + 1] << '\n';
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