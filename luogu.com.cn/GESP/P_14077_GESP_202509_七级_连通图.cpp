// #include<bits/stdc++.h>
// #define ll long long

// using namespace std;

// vector<int> g[100005];

// int f[100005];

// void init(int n) {
//     for (int i = 1; i <= n; i++) f[i] = i;
// }

// int find(int x) {
//     if (f[x] == x) return x;
//     return f[x] = find(f[x]);
// }

// void merge(int u, int v) {
//     int fu = find(u), fv = find(v);
//     if (fu != fv) f[fu] = fv;
// }

// void solve() {
//     int n, m;
//     cin >> n >> m;
//     init(n);
//     for (int i = 1; i <= m; i++) {
//         int u, v;
//         cin >> u >> v;
//         g[u].push_back(v);
//         g[v].push_back(u);
//         merge(u, v);
//     }
//     int cnt = 0;
//     for (int i = 1; i <= n; i++) {
//         for (int j = i + 1; j <= n; j++) {
//             if (find(i) != find(j)) {
//                 merge(i, j);
//                 cnt++;
//             }
//         }
//     }
//     cout << cnt << '\n';
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0), cout.tie(0);

//     // freopen("xxx.in", "r", stdin);
//     // freopen("xxx.out", "w", stdout);

//     int T = 1; // cin >> T;
//     while(T--) {
//         solve();
//     }

//     return 0;
// }

// TLE

#include<bits/stdc++.h>
#define ll long long

using namespace std;

bool vis[100005];
vector<int> g[100005];

void dfs(int u) {
    if (vis[u]) return ;
    vis[u] = true;
    for (auto v : g[u]) {
        dfs(v);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
            cnt++;
        }
    }
    cout << cnt - 1;
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