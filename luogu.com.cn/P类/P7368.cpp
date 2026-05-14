#include <bits/stdc++.h>
#define IAK std::ios::sync_with_stdio(false);
#define IOI std::cin.tie(nullptr)
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g;
    g.resize(n + 1);

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    vector<int> match(n + 1);
    vector<int> vis(n + 1);
    auto dfs = [&](auto&& self, int u) -> bool {
        for (int v : g[u]) {
            if (!vis[v]) {
                vis[v] = true;
                if (!match[v] || self(self, match[v])) {
                    match[v] = u;
                    return 1;
                }
            }
        }
        return 0;
    };
    int cnt = 0;

    for (int i = 1; i <= n; i++) {
        vis.clear();
        vis.resize(n + 1);
        if (dfs(dfs, i)) {
            cnt++;
        }
    }

    cout << cnt;
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