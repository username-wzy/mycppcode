#include<bits/stdc++.h>
#define ll long long

using namespace std;

constexpr int N = 2e5 + 5;

vector<int> g[N];

int ji = 0, ou = 0, n[N], vis[N];

void dfs(int x, int deep) {
    n[x] = deep % 2;
    if (deep % 2) ji++;
    else ou++;
    for (auto p : g[x]) {
        if (!vis[p]) {
            vis[p] = true;
            dfs(p, deep + 1);
            vis[p] = false;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vis[1] = true;
    dfs(1, 1);
    for (int i = 1; i <= n; i++) {
        if (::n[i]) cout << ji << " ";
        else cout << ou << " ";
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