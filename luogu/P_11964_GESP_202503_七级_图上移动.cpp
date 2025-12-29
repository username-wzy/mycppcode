#include<bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> g[505];

bool vis[505][25];

int n, m, k;

void dfs(int u, int step) {
    if (step > k) return ;
    if (vis[u][step]) return ;
    vis[u][step] = 1;
    for (auto v : g[u]) {
        dfs(v, step + 1);
    }
}

void solve() {
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(vis));
        dfs(i, 0);
        for (int j = 1; j <= k; j++) {
            int cnt = 0;
            for (int kk = 1; kk <= n; kk++) {
                cnt += vis[kk][j];
            }
            cout << cnt << " ";
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // freopen("xxx.in", "r", stdin);
    // freopen("xxx.out", "w", stdout);

    int T = 1; // cin >> T;
    while(T--) {c
        solve();
    }

    return 0;
}