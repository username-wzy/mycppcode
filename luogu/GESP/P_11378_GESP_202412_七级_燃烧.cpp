#include<bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> w, g[100005];
int vis[100005];

int dfs(int u) {
    if (vis[u]) return vis[u];
    int cnt = 0;
    for (auto v : g[u]) {
        if (w[v] < w[u]) cnt += dfs(v);
    }
    return vis[u] = cnt + 1;
}

void solve() {
    int n;
    cin >> n;
    w.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        mx = max(mx, dfs(i));
    }
    cout << mx << '\n';
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