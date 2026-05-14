#include <bits/stdc++.h>
#define debug(...) cerr << #__VA_ARGS__ << " = " << __VA_ARGS__ << endl;
#define IAK std::ios::sync_with_stdio(false);
#define IOI std::cin.tie(nullptr)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<long, long>;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> color(n + 1, -1);
    vector<int> cnt(3, 0);
    color[1] = 0;

    auto dfs = [&](auto&& self, ll u, ll c) -> bool {
        color[u] = c;
        cnt[c]++;
        for (int v : g[u]) {
            if (color[v] == color[u])
                return 0;
            if (!color[v]) {
                self(self, v, 3 - c);
            }
        }
        return 1;
    };

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        cnt[1] = cnt[2] = 0;
        if (!color[i] && !dfs(dfs, i, 1)) {
            cout << "Impossible";
            return;
        }
        ans += min(cnt[1], cnt[2]);
    }
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