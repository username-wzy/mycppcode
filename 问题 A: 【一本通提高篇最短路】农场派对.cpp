#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << '\n';
#define IAK std::ios::sync_with_stdio(false);
#define IOI std::cin.tie(nullptr)
using namespace std;
typedef long long ll;
#define pll pair<ll, ll>

vector<vector<pll>> g;

vector<ll> dijkstra(int start, int n)
{
    vector<ll> dist(n + 1, 1e18);
    dist[start] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> q;
    q.push({ 0, start });

    while (!q.empty()) {
        auto p = q.top();
        ll d = p.first, u = p.second;
        q.pop();
        if (d > dist[u])
            continue;
        for (auto p : g[u]) {
            ll v = p.first, w = p.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                q.push({ dist[v], v });
            }
        }
    }

    return dist;
}

void solve()
{
    int n, m, start;
    cin >> n >> m >> start;

    g.resize(n + 1);

    for (int i = 1; i <= m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({ v, w });
    }

    const auto dist1 = dijkstra(start, n);

    ll ans = 0;

    for (int i = 1; i <= n; i++) {
        auto dist = dijkstra(i, n);
        ans = max(ans, dist[start] + dist1[i]);
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