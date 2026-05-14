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
    vector<vector<pair<int, int>>> g(n + 1);
    int l = 0, r = 0;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({ v, w });
        g[v].push_back({ u, w });
        r = max(w, r);
    }

    auto check = [&](int mid) {
        vector<int> color(n + 1, -1);
        auto dfs = [&](auto&& self, int u, bool last_color) -> bool {
            color[u] = last_color;
            for (auto [v, w] : g[u]) {
                if (w <= mid)
                    continue;
                if (color[v] == color[u])
                    return 0;
                else if (color[v] == -1 && !self(self, v, !last_color))
                    return false;
            }
            return true;
        };
        for (int i = 1; i <= n; i++) {
            if (color[i] == -1)
                if (!dfs(dfs, i, 1))
                    return false;
        }
        return true;
    };

    int ans = 0;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            r = mid - 1;
            ans = mid;
        } else
            l = mid + 1;
    }

    cout << ans << '\n';
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