#include<bits/stdc++.h>
#define ll long long

using namespace std;


int n, m;

bool spfa(vector<int> &dis, vector<pair<int, int>> &g) {
    queue<int> q;
    dis[n + 1] = 0;
    vector<bool> vis(n, false);
    q.push(n + 1);
    unordered_map<int, int> mp;
    vis[n + 1] = true;
    mp[n + 1]++;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for (auto [v, w] : g[u]) {
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                if (!vis[v]) {
                    q.push(v);
                    mp[v]++;
                    if (mp[v] > n + 1) return false;
                    vis[v] = true;
                }
            }
        }
    }
    return true;
}

void solve() {
    vector<int> dis(int(1e2 + 5), 1e18);
    vector<pair<int, int>> g[int(1e3 + 5)];
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u - 1].push_back({v, w});
        g[v].push_back({u - 1, -w});
    }
    for (int i = 1; i <= n; i++) g[n + 1].push_back({i, 0});
    if (spfa(dis, g)) {
        cout << "true\n";
    } else {
        cout << "false\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // freopen("xxx.in", "r", stdin);
    // freopen("xxx.out", "w", stdout);

    int T = 1; cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}