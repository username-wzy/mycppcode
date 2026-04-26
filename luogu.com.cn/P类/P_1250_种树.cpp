#include<bits/stdc++.h>
#define int long long

using namespace std;

vector<int> dis((int)(3e4 + 5), LLONG_MIN);
vector<pair<int, int>> g[(int)(3e4 + 5)];
int n, m;

void spfa() {
    queue<int> q;
    vector<bool> vis(n + 1, false);
    for (int i = 0; i <= n; i++) {
        q.push(i);
        vis[i] = true;
        dis[i] = 0;
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for (auto [v, w] : g[u]) {
            if (dis[v] < dis[u] + w && dis[v] != LLONG_MIN) {
                dis[v] = dis[u] + w;
                if (!vis[v]) {
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        g[i].push_back({i + 1, 0});
    }
    for (int i = 1; i <= n; i++) {
        g[i].push_back({i - 1, -1});
    }
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u - 1].push_back({v, w});
    }
    spfa();
    cout << dis[n];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // freopen("xxx.in", "r", stdin);
    // freopen("xxx.out", "w", stdout);

    int T = 1; // cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}