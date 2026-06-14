#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << '\n';
#define IAK std::ios::sync_with_stdio(false);
#define IOI std::cin.tie(nullptr)
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

vector<vector<pll>> g;

void solve()
{
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    vector<ll> dist(n + 1, 1e18), cdist(n + 1, 1e18);
    dist[1] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> q;
    q.emplace(0, 1);
    while (!q.empty()) {
        auto p = q.top();
        ll d = p.first, u = p.second;
        q.pop();

        if (d > cdist[u])
            continue;

        for (auto p : g[u]) {
            int v = p.first, w = p.second;
            ll nxt = d + w;
            // 情况 1：可以更新最短路
            if (nxt < dist[v]) {
                cdist[v] = dist[v]; // 原最短路变成次短路
                dist[v] = nxt; // 更新最短路
                q.emplace(dist[v], v);
                if (cdist[v] != 1e18) {
                    q.emplace(cdist[v], v);
                }
            }
            // 情况 2：比最短路长，但比次短路短（保证严格次小）
            else if (nxt > dist[v] && nxt < cdist[v]) {
                cdist[v] = nxt; // 更新次短路
                q.emplace(cdist[v], v);
            }
        }
    }
    cout << cdist[n];
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