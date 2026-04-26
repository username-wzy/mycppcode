#include<bits/stdc++.h>
#define ll long long

using namespace std;

bool color[100005];
vector<int> g[100005];
int maxn = 0;

void dfs(int x, int step, int f) {
    maxn = max(maxn, step);
    for (auto p : g[x]) {
        if (color[p] != color[x] && f != p) {
            // vis[p] = true;
            dfs(p, step + 1, x);
            // vis[p] = false;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> color[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) dfs(i, 1, -1);
    cout << maxn;
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