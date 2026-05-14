#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << '\n';
#define IAK std::ios::sync_with_stdio(false);
#define IOI std::cin.tie(nullptr)

using namespace std;
typedef long long ll;

const int inf = 0x3f3f3f3f;

pair<int, vector<int>> spfa(int n, int s, const vector<vector<pair<int, int>>>& g)
{
    vector<int> dist(n + 1, inf);
    vector<bool> in_queue(n + 1, false);
    queue<int> q;
    vector<int> path(n + 1, -1);

    dist[s] = 0;
    q.push(s);
    in_queue[s] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        in_queue[u] = false;

        for (const auto& edge : g[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] != inf && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                path[v] = u;

                if (!in_queue[v]) {
                    q.push(v);
                    in_queue[v] = true;
                }
            }
        }
    }
    return { dist[n], path };
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({ v, w });
    }

    auto res = spfa(n, 1, g);
    cout << res.first << '\n';
    vector<int> path;
    for (int i = n; i != -1; i = res.second[i]) {
        path.push_back(i);
    }
    reverse(path.begin(), path.end());
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
    }
}

int main()
{
    IAK IOI;
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}