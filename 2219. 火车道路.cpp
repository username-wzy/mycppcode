#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> g[500005];
int fa[500005][20];
int dep[500005];
int dsu[500005]; // 并查集，用于跳过已访问的节点
bool vis[500005]; // 记录城市是否经过
int n, m, a;

// 1. 使用 BFS 替代 DFS，防止深度过大导致栈溢出
void pre_bfs(int root)
{
    queue<int> q;
    q.push(root);
    dep[root] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (v != fa[u][0]) {
                fa[v][0] = u;
                dep[v] = dep[u] + 1;
                q.push(v);
            }
        }
    }
}

void LCA_pre()
{
    for (int i = 1; i <= 19; i++)
        for (int u = 1; u <= n; u++)
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
}

int get_lca(int u, int v)
{
    if (dep[u] < dep[v])
        swap(u, v);
    for (int i = 19; i >= 0; i--) {
        if (dep[fa[u][i]] >= dep[v])
            u = fa[u][i];
    }
    if (u == v)
        return u;
    for (int i = 19; i >= 0; i--) {
        if (fa[u][i] != fa[v][i]) {
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    return fa[u][0];
}

ll query(int u, int v)
{
    return (ll)dep[u] + dep[v] - 2 * dep[get_lca(u, v)];
}

// 并查集寻找最近的未访问过的祖先
int find_dsu(int x)
{
    return dsu[x] == x ? x : dsu[x] = find_dsu(dsu[x]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> n >> m >> a))
        return 0;

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    pre_bfs(a);
    LCA_pre();

    // 初始化并查集和访问数组
    for (int i = 0; i <= n; i++) {
        dsu[i] = i;
        vis[i] = false;
    }

    ll ans = 0;
    int current = a; // 火车当前所在位置

    // 起点默认经过
    vis[current] = true;
    dsu[current] = find_dsu(fa[current][0]);

    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;

        // 核心修正：如果当前目标城市在之前的行程中已经被路过了，则直接跳过
        if (vis[x])
            continue;

        ans += query(current, x);
        int lca = get_lca(current, x);

        // 标记从 current 一路向上到 lca 的所有节点为已经过
        int u = find_dsu(current);
        while (dep[u] > dep[lca]) {
            vis[u] = true;
            dsu[u] = find_dsu(fa[u][0]); // 将当前点连接到父节点
            u = find_dsu(u); // 直接跳到下一个未访问的祖先
        }

        // 标记从 x 一路向上到 lca 的所有节点为已经过
        u = find_dsu(x);
        while (dep[u] > dep[lca]) {
            vis[u] = true;
            dsu[u] = find_dsu(fa[u][0]);
            u = find_dsu(u);
        }

        // 标记 lca 自己
        if (!vis[lca]) {
            vis[lca] = true;
            dsu[lca] = find_dsu(fa[lca][0]);
        }

        // 更新火车位置
        current = x;
    }

    cout << ans << "\n";
    return 0;
}