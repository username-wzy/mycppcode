#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> g[205];
bool vis[205];
int match[205];
bool floyd[205][205];

bool dfs(int u)
{
    for (auto v : g[u]) {
        if (!vis[v]) {
            vis[v] = true;
            if (!match[v] || dfs(match[v])) {
                match[v] = u;
                return 1;
            }
        }
    }
    return 0;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        floyd[u][v] = true;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (floyd[i][k] && floyd[k][j]) {
                    floyd[i][j] = true;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (floyd[i][j]) {
                g[i].push_back(j);
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof vis);
        cnt += dfs(i);
    }
    cout << cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}