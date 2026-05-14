#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << '\n';
#define IAK std::ios::sync_with_stdio(false);
#define IOI std::cin.tie(nullptr)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<long, long>;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int idx = 0, dist = 0;

    auto dfs = [&](int u, int fa, int dis, auto&& self) -> void {
        if (dis > dist) {
            dist = dis;
            idx = u;
        }
        for (int v : g[u]) {
            if (v != fa) {
                self(v, u, dis + 1, self);
            }
        }
    };

    dfs(1, 0, 0, dfs);
    dist = 0;
    dfs(idx, 0, 0, dfs);

    // if (k == 1)
    cout << 2 * (n - 1) - dist + 1;
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