#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << '\n';
#define IAK std::ios::sync_with_stdio(false);
#define IOI std::cin.tie(nullptr)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<long, long>;

vector<int> g[100005];
int dist[100005];

int dfs(int u)
{
    if (dist[u] != -1)
        return dist[u]; // 直接返回已知结果

    int max_len = 0;
    for (int v : g[u]) {
        max_len = max(max_len, dfs(v) + 1);
    }
    return dist[u] = max_len; // 记录并返回
}
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    memset(dist, -1, sizeof dist);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, dfs(i));
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