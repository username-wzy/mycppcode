#include<bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> g[1005];
int match[1005], vis[1005];

bool dfs(int u) {
    for (auto v : g[u]) {
        if (!vis[v]) {
            vis[v] = true;
            if (!match[v] || dfs(match[v])) {
                match[v] = u;
                return 1 ;
            }
        }
    }
    return 0;
}

void solve() {
    int n, k; // 9分救一下
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        y += n;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(vis));
        cnt += dfs(i);
    }
    cout << cnt;
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