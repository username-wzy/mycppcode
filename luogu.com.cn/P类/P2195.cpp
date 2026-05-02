#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

constexpr int N = 3e5 + 5;
vector<int> g[N];
int d[N];
int fa[N], tot = 0;

void init()
{
    for (int i = 1; i < N; i++)
        fa[i] = i;
}

int find(int x)
{
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int dfs(int u, int fa)
{
    int dist = 0, d1 = 0, d2 = 0; // dist: 当前节点到子树的最长距离，d1: 当前节点到子树的最长距离，d2: 当前节点到子树的次长距离
    for (int v : g[u]) {
        if (v == fa)
            continue;
        int d = dfs(v, u) + 1; // 当前节点到子树的距离
        dist = max(dist, d);
        if (d > d1) { // 更新最长距离和次长距离
            d2 = d1; // 更新次长距离
            d1 = d; // 更新最长距离
        } else if (d > d2)
            d2 = d; // 更新最长距离
    }
    tot = max(tot, d1 + d2);
    return dist;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    init();

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        int fu = find(u), fv = find(v);
        if (fu != fv)
            fa[fu] = fv;
    }

    for (int i = 1; i <= n; i++) {
        if (fa[i] == i) {
            tot = 0;
            dfs(i, -1);
            d[i] = tot;
        }
    }

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            cin >> x;
            cout << d[find(x)] << "\n"; // 输出当前节点所在树的直径
        } else {
            int u, v;
            cin >> u >> v;
            int fu = find(u), fv = find(v);
            if (fu == fv)
                continue;
            int val = max({ d[fu], d[fv], (d[fu] + 1) / 2 + (d[fv] + 1) / 2 + 1 }); // 连接两棵树后，新的树的直径可能是原来两棵树的直径，也可能是连接两棵树的最长路径
            fa[fu] = fv;
            d[fv] = val; // 更新新的树的直径
        }
    }
    return 0;
}