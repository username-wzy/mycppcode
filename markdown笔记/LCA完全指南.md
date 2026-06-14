# LCA（最近公共祖先）完全指南

## 一、LCA 求解方法

---

### 方法 1：树上倍增（Binary Lifting）

**原理：** 预处理每个节点的 `up[u][i]` 表示从 u 向上跳 2^i 步到达的祖先。查询时先将深度大的节点跳到同一深度，然后一起向上跳。

**预处理 O(n log n)，查询 O(log n)**

```cpp
#include <bits/stdc++.h>
using namespace std;

class LCA_BinaryLifting {
private:
    int n, logn;
    vector<int> dep;
    vector<vector<int>> up;

    void dfs(int u, int fa, const vector<vector<int>>& adj) {
        dep[u] = dep[fa] + 1;
        up[u][0] = fa;
        for (int i = 1; i <= logn; i++)
            up[u][i] = up[up[u][i - 1]][i - 1];
        for (int v : adj[u])
            if (v != fa)
                dfs(v, u, adj);
    }

public:
    LCA_BinaryLifting(int n, int root, const vector<vector<int>>& adj) {
        this->n = n;
        logn = ceil(log2(n));
        dep.resize(n + 1);
        up.assign(n + 1, vector<int>(logn + 1));
        dfs(root, 0, adj);
    }

    int getLCA(int u, int v) {
        if (dep[u] < dep[v]) swap(u, v);
        for (int j = logn; j >= 0; j--)
            if (dep[u] - (1 << j) >= dep[v])
                u = up[u][j];
        if (u == v) return u;
        for (int j = logn; j >= 0; j--)
            if (up[u][j] != up[v][j])
                u = up[u][j], v = up[v][j];
        return up[u][0];
    }

    int getDist(int u, int v) {
        return dep[u] + dep[v] - 2 * dep[getLCA(u, v)];
    }
};
```

**BFS 版本（防止栈溢出）：**
```cpp
void bfs(int root, const vector<vector<int>>& adj) {
    queue<int> q;
    q.push(root);
    dep[root] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (v == fa[u][0]) continue;
            fa[v][0] = u;
            dep[v] = dep[u] + 1;
            q.push(v);
        }
    }
}
void build(int n) {
    for (int i = 1; i <= 19; i++)
        for (int u = 1; u <= n; u++)
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
}
```

---

### 方法 2：Tarjan 离线算法

**原理：** 利用 DFS 回溯和并查集，在遍历过程中回答所有查询。当遍历到 u 时，若 v 已被访问，则 lca(u,v) = find(v)。

**O(n + m)（线性！），但只能离线**

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
vector<int> g[N];
vector<pair<int, int>> query[N];
int fa[N], ans[N];
bool vis[N];

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void tarjan(int u) {
    vis[u] = true;
    for (int v : g[u]) {
        if (vis[v]) continue;
        tarjan(v);
        fa[v] = u; // merge(v, u)
    }
    for (auto [v, id] : query[u]) {
        if (vis[v])
            ans[id] = find(v);
    }
}

void solve() {
    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        if (u == v) ans[i] = u;
        else {
            query[u].emplace_back(v, i);
            query[v].emplace_back(u, i);
        }
    }
    tarjan(s);
    for (int i = 1; i <= m; i++)
        cout << ans[i] << '\n';
}
```

---

### 方法 3：欧拉序 + RMQ（Sparse Table）

**原理：** 对树做 DFS 得到欧拉序（每个节点出入时都记录），两点 LCA 就是它们在欧拉序中首次出现位置之间深度最小的节点。

**预处理 O(n log n)，查询 O(1)**

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> g[N];
int euler[N * 2], dep[N * 2], first[N], cnt;
int st[20][N * 2], logn[N * 2];

void dfs(int u, int fa, int d) {
    first[u] = ++cnt;
    euler[cnt] = u;
    dep[cnt] = d;
    for (int v : g[u]) {
        if (v == fa) continue;
        dfs(v, u, d + 1);
        euler[++cnt] = u;
        dep[cnt] = d;
    }
}

void buildRMQ() {
    logn[0] = -1;
    for (int i = 1; i <= cnt; i++) {
        logn[i] = logn[i >> 1] + 1;
        st[0][i] = i;
    }
    for (int j = 1; (1 << j) <= cnt; j++)
        for (int i = 1; i + (1 << j) - 1 <= cnt; i++) {
            int l = st[j - 1][i], r = st[j - 1][i + (1 << (j - 1))];
            st[j][i] = (dep[l] < dep[r]) ? l : r;
        }
}

int rmq(int l, int r) {
    if (l > r) swap(l, r);
    int k = logn[r - l + 1];
    int a = st[k][l], b = st[k][r - (1 << k) + 1];
    return (dep[a] < dep[b]) ? euler[a] : euler[b];
}

int getLCA(int u, int v) {
    return rmq(first[u], first[v]);
}
```

---

### 方法 4：树链剖分（Heavy-Light Decomposition）

**原理：** 将树剖分成重链和轻链，LCA 就是两个节点不断跳到所在链顶，直到在同一条链上。

**预处理 O(n)，查询 O(log n)**

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
vector<int> g[N];
int fa[N], dep[N], sz[N], son[N], top[N];

void dfs1(int u, int f) {
    fa[u] = f;
    dep[u] = dep[f] + 1;
    sz[u] = 1;
    int maxsz = -1;
    for (int v : g[u]) {
        if (v == f) continue;
        dfs1(v, u);
        sz[u] += sz[v];
        if (sz[v] > maxsz) maxsz = sz[v], son[u] = v;
    }
}

void dfs2(int u, int t) {
    top[u] = t;
    if (!son[u]) return;
    dfs2(son[u], t);
    for (int v : g[u])
        if (v != fa[u] && v != son[u])
            dfs2(v, v);
}

int getLCA(int u, int v) {
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) swap(u, v);
        u = fa[top[u]];
    }
    return dep[u] < dep[v] ? u : v;
}

// init: dfs1(root, 0); dfs2(root, root);
```

---

### 方法 5：朴素爬山法（Naive）

**原理：** 深度大的节点不断向上跳，直到两节点相遇。用于特殊树（如因子树、父节点有数学规律）。

**O(depth) 最坏 O(n)**

```cpp
int LCA(int x, int y) {
    while (x != y) {
        if (x > y) x = parent(x);
        else       y = parent(y);
    }
    return x;
}
// 示例：x 的父节点为 x 的最大真因子（最小质因子对应因子）
int parent(int x) {
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return x / i;
    return 1;
}
```

---

### 方法对比

| 方法 | 预处理 | 单次查询 | 空间 | 特点 |
|------|--------|----------|------|------|
| 树上倍增 | O(n log n) | O(log n) | O(n log n) | 在线，可维护额外信息（max, min, sum） |
| Tarjan | O(n + m) | O(1) (离线) | O(n + m) | 离线，线性复杂度 |
| 欧拉序+RMQ | O(n log n) | O(1) | O(n log n) | 在线查询最快 |
| 树链剖分 | O(n) | O(log n) | O(n) | 可维护路径信息，常数小 |
| 朴素爬山 | O(1) | O(depth) | O(1) | 适用特殊树结构 |

---

## 二、LCA 应用场景

---

### 应用 1：树上两点距离

**公式：** `dist(u, v) = dep[u] + dep[v] - 2 * dep[lca(u, v)]`

```cpp
int getDist(int u, int v, LCA_BinaryLifting& lca) {
    return lca.getDist(u, v);
}
```

**带权树上的距离：**
```cpp
// 预处理 dist[u] = 根到 u 的路径权值和
// dist(u, v) = dist[u] + dist[v] - 2 * dist[lca]
ll query(int x, int y) {
    return dist[x] + dist[y] - 2 * dist[get_lca(x, y)];
}
```

---

### 应用 2：树上差分（点差分 / 边差分）

**点差分：** 路径 `u -> v` 上每个点权值 +1
```
diff[u]++, diff[v]++, diff[lca]--, diff[fa[lca]]--
```

**边差分：** 路径 `u -> v` 上每条边权值 +1
```
diff[u]++, diff[v]++, diff[lca] -= 2
```

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
vector<int> g[N];
int fa[N][20], dep[N], diff[N];
int n, ans = 0;

void dfs_pre(int u, int f) {
    dep[u] = dep[f] + 1;
    fa[u][0] = f;
    for (int i = 1; i <= 19; i++)
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (int v : g[u])
        if (v != f) dfs_pre(v, u);
}

int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = 19; i >= 0; i--)
        if (dep[fa[u][i]] >= dep[v]) u = fa[u][i];
    if (u == v) return u;
    for (int i = 19; i >= 0; i--)
        if (fa[u][i] != fa[v][i])
            u = fa[u][i], v = fa[v][i];
    return fa[u][0];
}

void dfs_calc(int u, int f) {
    for (int v : g[u]) {
        if (v == f) continue;
        dfs_calc(v, u);
        diff[u] += diff[v];
    }
    ans = max(ans, diff[u]);
}

// 每条路径 (u, v) 上点权 +1
void add_path(int u, int v) {
    int w = lca(u, v);
    diff[u]++; diff[v]++;
    diff[w]--; diff[fa[w][0]]--;
}
```

---

### 应用 3：三点汇聚（紧急集合）

**问题：** 找到一点使三个点到该点的距离和最小。

**结论：** 汇聚点为三个 LCA 中深度最大的那个，距离和为 `dep[x]+dep[y]+dep[z] - dep[lca(x,y)] - dep[lca(y,z)] - dep[lca(x,z)]`

```cpp
// 1580. 紧急集合
int get_LCA(int u, int v) { /* 树上倍增 LCA */ }

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    // 建图...
    pre_bfs(); LCA_pre();

    while (q--) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        int a = get_LCA(x, y);
        int b = get_LCA(y, z);
        int c = get_LCA(x, z);

        int p;
        if (dep[a] >= dep[b] && dep[a] >= dep[c])      p = a;
        else if (dep[b] >= dep[a] && dep[b] >= dep[c]) p = b;
        else                                           p = c;

        ll ans = (ll)dep[x] + dep[y] + dep[z] - dep[a] - dep[b] - dep[c];
        printf("%d %lld\n", p, ans);
    }
}
```

---

### 应用 4：树上路径覆盖（路径标记、区间覆盖）

**问题：** 给定一系列路径，问每个点/边被覆盖了多少次。用树上差分 O(1) 标记每条路径，最后 DFS 累加。

```cpp
// 核心：对每条路径 (u,v) 做差分标记
diff[u]++, diff[v]++, diff[lca]--, diff[fa[lca]]--;
// DFS 累加后 diff[u] 即为 u 被覆盖的次数
```

---

### 应用 5：树上路径交

**问题：** 判断两条路径 `(a,b)` 和 `(c,d)` 是否有交，若有交求出交点路径。

**判断有交：** 一条路径的 LCA 在另一条路径上。
```cpp
bool onPath(int p, int u, int v, LCA_BinaryLifting& lca) {
    return lca.getDist(u, p) + lca.getDist(p, v) == lca.getDist(u, v);
}
bool intersect(int a, int b, int c, int d, LCA_BinaryLifting& lca) {
    int p = lca.getLCA(a, b);
    return onPath(c, a, b, lca) || onPath(d, a, b, lca)
        || onPath(a, c, d, lca) || onPath(b, c, d, lca);
}
```

---

### 应用 6：路径上最大/最小边权

**原理：** 倍增时额外维护 `mx[u][i]` 表示从 u 向上跳 2^i 步经过的最大边权。

```cpp
const int N = 1e5 + 5;
vector<pair<int, int>> g[N];
int fa[N][20], mx[N][20], dep[N];

void dfs(int u, int f, int w) {
    fa[u][0] = f;
    mx[u][0] = w;
    dep[u] = dep[f] + 1;
    for (int i = 1; i <= 19; i++) {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
        mx[u][i] = max(mx[u][i - 1], mx[fa[u][i - 1]][i - 1]);
    }
    for (auto [v, w2] : g[u])
        if (v != f) dfs(v, u, w2);
}

int queryMax(int u, int v) {
    int ans = 0;
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = 19; i >= 0; i--)
        if (dep[fa[u][i]] >= dep[v])
            ans = max(ans, mx[u][i]), u = fa[u][i];
    if (u == v) return ans;
    for (int i = 19; i >= 0; i--)
        if (fa[u][i] != fa[v][i]) {
            ans = max(ans, max(mx[u][i], mx[v][i]));
            u = fa[u][i], v = fa[v][i];
        }
    return max(ans, max(mx[u][0], mx[v][0]));
}
```

---

### 应用 7：次小生成树（严格次小生成树）

**原理：** 先求 MST，然后枚举非树边 `(u, v, w)`，用 `w` 替换路径 `u->v` 上的最大边（若最大边 == w 则替换次大边）。

```cpp
// 需要倍增维护路径最大值和次大值
struct Edge {
    int u, v, w;
    bool used; // 是否为树边
};
// Kruskal 求 MST
// 建 MST 树
// 倍增预处理 fa[u][i], mx1[u][i](最大), mx2[u][i](次大)
// 枚举每条非树边尝试替换
```

---

### 应用 8：路径和（点权/边权和查询）

```cpp
// 预处理 sum[u] = 根到 u 的路径权值和
// pathSum(u, v) = sum[u] + sum[v] - 2 * sum[lca] + val[lca]（点权）
// pathSum(u, v) = sum[u] + sum[v] - 2 * sum[lca]（边权）

ll pathSum(int u, int v, LCA_BinaryLifting& lca, ll sum[]) {
    int w = lca.getLCA(u, v);
    return sum[u] + sum[v] - 2 * sum[w]; // 边权
    // return sum[u] + sum[v] - 2 * sum[w] + val[w]; // 点权
}
```

---

### 应用 9：判断两点是否在根的不同子树

**问题：** 给定根 `root` 和两点 `u, v`，判断它们是否在 `root` 的不同子树中。
**解法：** `lca(u, v) == root` 且 `u != root && v != root`。

---

### 应用 10：动态规划 + LCA（树上路径统计）

**问题：** 统计树上所有点对中满足某种路径权值条件（如路径权值和 % 3 == 0）的数量。
**解法：** 点分治或树形 DP + LCA 距离公式。

```cpp
// P2634 聪聪可可：统计路径长为 3 的倍数的点对数量
// 方案 1：LCA + O(n^2) 枚举（60分）
// 方案 2：树形 DP O(n)
```

---

## 三、经典例题列表

| 题目 | 平台 | 方法 | 说明 |
|------|------|------|------|
| P3379 【模板】最近公共祖先（LCA） | 洛谷 | 倍增/Tarjan/树剖 | LCA 模板题 |
| P3128 [USACO15DEC] Max Flow P | 洛谷 | 树上差分 | 点差分模板 |
| P2680 运输计划 | 洛谷 | LCA + 二分 + 差分 | 路径覆盖 + 二分答案 |
| P3258 [JLOI2014] 松鼠的新家 | 洛谷 | 树上差分 | 路径点权差分 |
| P4281 [AHOI2008] 紧急集合 | 洛谷/ACoder | LCA | 三点汇聚 |
| P2634 [国家集训队] 聪聪可可 | 洛谷 | LCA + 点分治/DP | 路径模统计 |
| 2219. 火车道路 | ACoder | LCA + 并查集 | 路径覆盖 + 路径压缩跳跃 |
| P4180 [BJWC2010] 严格次小生成树 | 洛谷 | LCA + 倍增 | 路径最大/次大值 |
| P1967 货车运输 | 洛谷 | 最大生成树 + LCA | 路径最小值 |
| SPOJ COT / P2633 Count on a tree | SPOJ/洛谷 | 主席树 + LCA | 树上第 k 小 |
| P4559 [JSOI2009] 团队 | 洛谷 | LCA + 排序 | 路径交问题 |
| CF 191C Fools and Roads | Codeforces | 树上差分 | 边差分模板 |
| CF 519E A and B and Lecture Rooms | Codeforces | LCA + 分类讨论 | 到两点距离相等点数 |
