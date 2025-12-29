#include<bits/stdc++.h>
#define int long long

using namespace std;

vector<pair<int, int>> g[1000005];
int mx = 0;
bool vis[1000005];

void dfs(int x,int cnt) {
    if (vis[x]) return ;
    vis[x] = true;
    for (auto p : g[x]) {
        dfs(p.first, cnt + p.second);
    }
    mx = max(mx, cnt);
}

void solve() {
    int n, sum = 0;
    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        sum += w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    sum *= 2;
    dfs(1, 0);
    cout << sum - mx;
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