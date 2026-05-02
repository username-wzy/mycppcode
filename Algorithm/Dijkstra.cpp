#include <bits/stdc++.h>
#define debug(...) cerr << #__VA_ARGS__ << " = " << __VA_ARGS__ << endl;
#define IAK std::ios::sync_with_stdio(false);
#define IOI std::cin.tie(nullptr)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<long, long>;

const int N = 205;

int t[N];
int n, m;
int dist[N];

vector<pll> g[N];

ll dijkstra(ll st, ll ed, ll time)
{
    priority_queue<pll, vector<pll>, greater<pll>> q;
    q.push({ 0, st });
    fill(dist, dist + n, 0x3f3f3f3f);
    dist[st] = 0;
    while (!q.empty()) {
        int u = q.top().second, weight = q.top().first;
        q.pop();
        if (weight > dist[u]) {
            continue;
        }
        for (auto [v, w] : g[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + weight;
                q.push({ dist[v], w });
            }
        }
    }
    return (dist[ed] == 0x3f3f3f3f ? -1 : dist[ed]);
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    for (int i = 1; i <= m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({ v, w });
    }
    int q;
    cin >> q;
    while (q--) {
        ll x, y, t;
        cin >> x >> y >> t;
        cout << dijkstra(x, y, t);
    }
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