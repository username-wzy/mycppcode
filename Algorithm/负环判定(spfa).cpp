#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << '\n';
#define IAK std::ios::sync_with_stdio(false);
#define IOI std::cin.tie(nullptr)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<long, long>;

const ll inf = 0x3f3f3f3f3f3f3f3f;

bool iffuhuan(int n, const vector<vector<pair<int, ll>>>& g)
{
    vector<ll> dist(n + 1, 0);
    vector<bool> in_queue(n + 1, true);
    vector<int> cnt(n + 1, 0);
    queue<int> q;

    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        in_queue[u] = false;

        for (const auto& edge : g[u]) {
            int v = edge.first;
            ll w = edge.second;

            if (dist[u] != inf && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                cnt[v] = cnt[u] + 1;

                if (!in_queue[v]) {
                    q.push(v);
                    in_queue[v] = true;

                    if (cnt[v] >= n) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

vector<ll> spfa(int n, int s, const vector<vector<pair<int, ll>>>& g)
{
    vector<ll> dist(n + 1, inf);
    vector<bool> in_queue(n + 1, false);
    queue<int> q;
    q.push(s);
    in_queue[s] = true;
    dist[s] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        in_queue[u] = false;
        for (const auto& edge : g[u]) {
            int v = edge.first;
            ll w = edge.second;
            if (dist[u] != inf && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                if (!in_queue[v]) {
                    q.push(v);
                    in_queue[v] = true;
                }
            }
        }
    }
    return dist;
}

void solve()
{
    int n, m, s;
    cin >> n >> m >> s;
    vector<vector<pair<int, ll>>> g(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({ v, w });
    }
    mt19937 rng(520131420131016);
    for (int i = 1; i <= n; i++) {
        shuffle(g[i].begin(), g[i].end(), rng);
    }
    bool fuhuan = iffuhuan(n, g);
    if (fuhuan) {
        cout << "-1";
    } else {
        vector<ll> dist = spfa(n, s, g);
        for (int i = 1; i <= n; i++) {
            if (dist[i] == inf) {
                cout << "NoPath\n";
            } else
                cout << dist[i] << '\n';
        }
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