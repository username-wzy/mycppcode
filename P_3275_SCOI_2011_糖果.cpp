#include<bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> dis(int(1e5 + 5), 0);
vector<pair<int, int>> g[int(1e5 + 5)];
int n, m;

bool spfa() {
    queue<int> q;
    vector<bool> vis(n + 1, false);
    unordered_map<int, int> mp;
    
    for (int i = 1; i <= n; i++) {
        q.push(i);
        vis[i] = true;
        dis[i] = 1; // everyone need candy
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for (auto [v, w] : g[u]) {
            if (dis[v] < dis[u] + w) {
                dis[v] = dis[u] + w;
                if (!vis[v]) {
                    q.push(v);
                    mp[v]++;
                    if (mp[v] > n + 1) return false;
                    vis[v] = true;
                }
            }
        }
    }
    return true;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) {
            g[u].push_back({v, 0});
            g[v].push_back({u, 0});
        } else if (op == 2) {
            g[u].push_back({v, 1});
        } else if (op == 3) {
            g[v].push_back({u, 0});
        } else if (op == 4) {
            g[v].push_back({u, 1});
        } else {
            g[u].push_back({v, 0});
        }
        if ((op == 2 || op == 4) && u == v) { // 因为op2 | 4 都是严格大于 |小于，如果 u == v显然不成立 输出-1
            cout << -1;
            return ;
        }
    }
    for (int i = 1; i<= n; i++) g[0].push_back({i, 0});
    if (spfa()) {
        ll ans = 0;
        for (int i = 1; i <= n; i++) ans += dis[i];
        cout << ans;
    } else {
        cout << -1;
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
/*
1. **X=1**（$A$ 与 $B$ 糖果数相等）：
   - $d_A \geq d_B+0$，加边 $B \rightarrow A$，权值 0。
   - $d_B \geq d_A+0$，加边 $A \rightarrow B$，权值 0。
2. **X=2**（$A$ 少于 $B$，严格）：
   - 转化为 $d_A \leq d_B-1$，即 $d_B \geq d_A+1$，加边 $A \rightarrow B$，权值 1。
3. **X=3**（$A$ 不少于 $B$）：
   - $d_A \geq d_B+0$，加边 $B \rightarrow A$，权值 0。
4. **X=4**（$A$ 多于 $B$，严格）：
   - 转化为 $d_A \geq d_B+1$，加边 $B \rightarrow A$，权值 1。
5. **X=5**（$A$ 不多于 $B$）：
   - $d_B \geq d_A+0$，加边 $A \rightarrow B$，权值 0。
*/