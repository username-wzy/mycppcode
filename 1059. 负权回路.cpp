#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll inf = 0x3f3f3f3f3f3f3f3f;
const int N = 1005;

vector<pair<int, ll>> g[N];
int n, m, s;

ll dist[N];
int cnt[N];
bool in_queue[N];

bool iffuhuan()
{
    fill(cnt, cnt + n + 1, 0);
    fill(in_queue, in_queue + n + 1, 0);

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
        in_queue[i] = 1;
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        in_queue[u] = 0;

        for (auto p : g[u]) {
            int v = p.first;
            ll w = p.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                cnt[v] = cnt[u] + 1;
                if (cnt[v] >= n)
                    return 1;
                if (!in_queue[v]) {
                    q.push(v);
                    in_queue[v] = 1;
                }
            }
        }
    }
    return 0;
}

void spfa(int s)
{
    fill(dist, dist + n + 1, inf);
    fill(cnt, cnt + n + 1, 0);
    fill(in_queue, in_queue + n + 1, 0);
    dist[s] = 0;

    queue<int> q;
    q.push(s);
    in_queue[s] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        in_queue[u] = 0;

        for (auto p : g[u]) {
            int v = p.first;
            ll w = p.second;
            if (dist[u] != inf && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                if (!in_queue[v]) {
                    q.push(v);
                    in_queue[v] = 1;
                }
            }
        }
    }
}

void solve()
{
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({ v, w });
    }

    bool fuhuan = iffuhuan();
    if (fuhuan) {
        cout << -1 << '\n';
    } else {
        spfa(s);
        for (int i = 1; i <= n; i++) {
            if (dist[i] == inf)
                cout << "NoPath\n";
            else
                cout << dist[i] << '\n';
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
