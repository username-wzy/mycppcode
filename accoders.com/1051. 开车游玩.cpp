#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;
#define IAK std::ios::sync_with_stdio(false);
#define IOI std::cin.tie(nullptr)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<long, long>;

const int N = 2505;

int n, m;
ll dist[N];

vector<pll> g[N];

ll dijkstra(ll st, ll ed)
{
    priority_queue<pll, vector<pll>, greater<pll>> q;
    q.push({ 0, st });
    fill(dist + 1, dist + n + 1, 0x3f3f3f3f3f3f3f3f);
    dist[st] = 0;
    while (!q.empty()) {
        int u = q.top().second, weight = q.top().first;
        q.pop();
        if (u == ed) {
            break;
        }
        if (weight > dist[u]) {
            continue;
        }
        for (auto p : g[u]) {
            int w = p.second, v = p.first;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                q.push({ dist[v], v });
            }
        }
    }
    return (dist[ed] == 0x3f3f3f3f3f3f3f3f ? -1 : dist[ed]);
}

void solve()
{
    cin >> n >> m;
    int st, ed;
    cin >> st >> ed;
    for (int i = 1; i <= m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({ v, w });
        g[v].push_back({ u, w });
    }
    cout << dijkstra(st, ed);
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