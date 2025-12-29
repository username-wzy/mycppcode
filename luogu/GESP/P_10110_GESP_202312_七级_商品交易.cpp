#include<bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> g[100005];
int vis[100005];

void solve() {
    int n, m, a, b, va, vb;
    cin >> n >> m >> a >> b;
    for (int i = 0; i < n; i++) {
        int w;
        cin >> w;
        if (i == a) {
            va = w;
        }
        if (i == b) {
            vb = w;
        }
    }
    // cerr << va << " " << vb;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);

    }
    queue<pair<int, int>> q;
    q.push({a, 0});
    vis[a] = true;
    int mx = INT_MAX;
    while (!q.empty()) {
        auto now = q.front(); q.pop();
        if (now.first == b) {
            mx = min(mx, now.second + vb - va);
        }
        for (auto v : g[now.first]) {
            if (!vis[v]) {
                q.push({v, now.second + 1});
                vis[v] = true;
            }
        }
    }
    if (mx == INT_MAX) {
        cout << "No solution";
    } else cout << mx;
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