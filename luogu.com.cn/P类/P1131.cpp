#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << '\n';
#define IAK std::ios::sync_with_stdio(false);
#define IOI std::cin.tie(nullptr)

using namespace std;

using ll = long long;
using pll = pair<int, ll>;

/**
 * @File: P1131
 * @Author: wzy
 * @Date: 2026-06-07 17:39
 */

constexpr int N = 5e5 + 5;

vector<pll> g[N];

ll dp[N], ans = 0;

void dfs(int u, int fa)
{
    for (const auto& [v, w] : g[u]) {
        if (v == fa)
            continue;
        dfs(v, u);
        dp[u] = max(dp[u], dp[v] + w);
    }
    for (const auto& [v, w] : g[u]) {
        if (v == fa)
            continue;
        ans += dp[u] - dp[v] - w;
    }
}

void solve()
{
    int n;
    cin >> n;
    int root;
    cin >> root;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    dfs(root, 0);
    cout << ans;
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