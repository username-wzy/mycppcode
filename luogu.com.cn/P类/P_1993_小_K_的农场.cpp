#include<bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> dis(int(1e5 + 5), 1e18);
vector<pair<int, int>> g[int(1e5 + 5)];
int n, m;

bool spfa() {
    queue<int> q;
    dis[0] = 0;
    vector<bool> vis(n + 1, false);
    q.push(0);
    unordered_map<int, int> mp;
    vis[0] = true;
    mp[0]++;
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
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int op, u, v, w;
        cin >> op >> u >> v;
        if (op == 1) {
            cin >> w;
            g[u].push_back({v, -w});
        } else if (op == 2) {
            cin >> w;
            g[v].push_back({u, w});
        } else {
            g[u].push_back({v, 0});
            g[v].push_back({u, 0});
        }
    }
    for (int i = 1; i<= n; i++) g[0].push_back({i, 0});
    if (spfa()) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}

int main() {
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