#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, K;
vector<pair<int, int>> adj[N]; // adj[u] = {v, edge_index}
int w[N]; // edge weight, indexed by edge_index
int fa[N], fa_edge[N]; // parent and parent-edge in BFS/DFS
int dep[N], dist[N];
bool vis[N];

// BFS求从s出发的最远点，返回最远点编号，dist[]记录距离
// 边权可能为-1，所以用SPFA式的BFS(实际上用两次DFS求树的直径)
// 由于有负权边，用DFS+DP求最长路

int d1, d2; // 两次求得的直径长度

// 对于K=1，树边权全为1，直接两次BFS求直径
// 对于K=2，第一次直径路径上边权取反后，需要在带负权的树上求最长路径
// 带负权树的直径用树形DP求

// BFS求最远点(仅用于全正权时)
int bfs(int s)
{
    memset(vis, false, sizeof(vis));
    queue<int> q;
    q.push(s);
    vis[s] = true;
    dist[s] = 0;
    fa[s] = 0;
    fa_edge[s] = -1;
    int far_node = s;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto [v, eid] : adj[u]) {
            if (!vis[v]) {
                vis[v] = true;
                dist[v] = dist[u] + w[eid];
                fa[v] = u;
                fa_edge[v] = eid;
                if (dist[v] > dist[far_node])
                    far_node = v;
                q.push(v);
            }
        }
    }
    return far_node;
}

// 树形DP求带负权树的最长路径(直径)
int ans_diam;

// 返回从u出发往子树走的最长链长度
int dfs_dp(int u, int father)
{
    int mx1 = 0, mx2 = 0; // 最长和次长链
    for (auto [v, eid] : adj[u]) {
        if (v == father)
            continue;
        int val = dfs_dp(v, u) + w[eid];
        if (val > mx1) {
            mx2 = mx1;
            mx1 = val;
        } else if (val > mx2) {
            mx2 = val;
        }
    }
    ans_diam = max(ans_diam, mx1 + mx2);
    return max(mx1, 0); // 如果最长链为负，不选
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> K;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back({ b, i });
        adj[b].push_back({ a, i });
        w[i] = 1;
    }

    // 第一次求直径：树边权全为1，用两次BFS
    int u = bfs(1);
    int v = bfs(u);
    d1 = dist[v];

    int base = 2 * (n - 1);

    if (K == 1) {
        cout << base - d1 + 1 << "\n";
        return 0;
    }

    // K == 2
    // 将第一条直径路径上的边权取反(-1)
    // 从v回溯到u，沿fa[]标记路径上的边
    int cur = v;
    while (cur != u) {
        w[fa_edge[cur]] = -1;
        cur = fa[cur];
    }

    // 第二次求直径：树上有负权边，用树形DP
    ans_diam = 0;
    dfs_dp(1, 0);
    d2 = ans_diam;

    cout << base - d1 + 1 - d2 + 1 << "\n";
    return 0;
}
