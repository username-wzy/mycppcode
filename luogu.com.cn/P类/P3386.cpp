#include <bits/stdc++.h>

using namespace std;

vector<int> g[505];
int match[505], vis[505];

int dfs(int u)
{
    for (int v : g[u]) {
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m, e;
    cin >> n >> m >> e;
    for (int i = 1; i <= e; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(vis));
        if (dfs(i))
            cnt++;
    }
    cout << cnt;
}
