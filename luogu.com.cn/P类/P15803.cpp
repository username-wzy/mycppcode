#include <bits/stdc++.h>
#define debug(...) cerr << #__VA_ARGS__ << " = " << __VA_ARGS__ << endl;
#define IAK std::ios::sync_with_stdio(false);
#define IOI std::cin.tie(nullptr)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<long, long>;

constexpr ll inf = 0x3f3f3f3f3f3f3f3f;

//

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<array<int, 3>>> g(n + 1);
    vector<array<int, 4>> e;
    for (int i = 0, u, v, w, b; i < m; i++) {
        cin >> u >> v >> w >> b;
        g[u].push_back({ b, v, w });
        g[v].push_back({ b, u, w });
        e.push_back({ u, v, w, b });
    }

    auto dijkstra = [&](int start, int d) {
        vector dist(n + 1, inf);
        dist[start] = 0;
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
        q.emplace(0, start);
        while (!q.empty()) {
            auto [cur_dist, u] = q.top();
            q.pop();
            if (cur_dist > dist[u])
                continue;
            for (auto& [b, v, w] : g[u]) {
                if (b > d)
                    continue;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    q.emplace(dist[v], v);
                }
            }
        }
        return dist;
    };
    ll ans = inf;
    for (auto& [u, v, w, b] : e) {
        vector d1 = dijkstra(1, b);
        vector dn = dijkstra(n, b);
        if (d1[u] != inf && dn[v] != inf) {
            ans = min(ans, d1[u] + dn[v]);
        }
        if (d1[v] != inf && dn[u] != inf) {
            ans = min(ans, d1[v] + dn[u]);
        }
    }
    cout << (ans == inf ? -1 : ans) << '\n';
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