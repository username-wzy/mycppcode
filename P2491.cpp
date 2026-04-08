/*
* **树网** = 带权无向连通树。
* **树的直径** = 树上最长的一条链。可以通过 **两次 DFS/BFS** 找出来（任意点找最远点 $S$，$S$ 找最远点 $T$）。
* **偏心距 (ECC)** = 树上所有点到某条路径 $F$ 的距离的 **最大值**。
* **点到路径的距离** = 点到路径上所有节点的距离的 **最小值**。
* **题目终极目标** = 在直径上滑动一个长度 $\le s$ 的窗口 $F$，让上述的最大值 **尽可能小**。

1. **外层**：双指针枚举直径路径上的起点 $i$ 和终点 $j$。
2. **过滤**：判断当前选取的路径 $F$ 长度是否 $\le s$。
3. **中层（找最大）**：枚举树上所有的点 $k$，计算它们到路径 $F$ 的距离，求最大的那个（这就是偏心距）。
4. **内层（求最短）**：计算点 $k$ 到路径 $F$ 的距离时，是在 $F$ 的所有点中找距离 $k$ 最小的。
5. **打擂台**：在所有合法的 $F$ 产生的偏心距中，取最小值 `ans`（别忘了 `ans` 初始值得设为无穷大）。
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

constexpr int N = 3e3 + 5;
vector<pair<int, int>> g[N];
int st, tot, cnt = 0, ed = 0;
int dp[N][N]; // dp[i][j] = i 到 j 的距离
int pre[N]; // 记录路径上的前驱节点，方便后续重建路径

void dfs(int u, int fa, int dis)
{
    if (dis > tot) {
        tot = dis;
        st = u;
    }
    for (auto [v, w] : g[u]) {
        if (v == fa)
            continue;
        dfs(v, u, dis + w);
    }
}

void dfs2(int u, int fa, int dis)
{
    if (dis > tot) {
        tot = dis;
        ed = u;
    }
    pre[u] = fa;
    for (auto [v, w] : g[u]) {
        if (v == fa)
            continue;
        dfs2(v, u, dis + w);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s;
    cin >> n >> s;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)
                dp[i][j] = 0;
            else
                dp[i][j] = 1e9;
        }
    }

    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dp[u][v] = dp[v][u] = w;
        g[u].push_back({ v, w });
        g[v].push_back({ u, w });
    }

    dfs(1, -1, 0); // 第一次 DFS 找到直径的一个端点 st
    tot = 0;
    dfs2(st, -1, 0); // 第二次 DFS 从 st 出发找到直径的另一个端点 ed，同时记录路径上的前驱节点
    cerr << st << " " << ed;

    vector<int> path;
    for (int i = ed; i != st; i = pre[i])
        path.push_back(i);
    path.push_back(st); // 别忘了把 st 加入路径
    reverse(path.begin(), path.end());

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]); // Floyd-Warshall 算法预处理所有点对之间的距离
            }
        }
    }

    int ans = 1e9;
    const int path_len = path.size();
    for (int i = 0; i < path_len; i++) { // 双指针枚举路径上的起点 i 和终点 j
        for (int j = i; j < path_len; j++) {    
            if (dp[path[i]][path[j]] <= s) { // 过滤：判断当前选取的路径长度是否 <= s
                int ecc = 0;
                for (int k = 1; k <= n; k++) { // 枚举树上所有的点 k，计算它们到路径 F 的距离，求最大的那个（这就是偏心距）
                    int min_d = 1e9;
                    for (int p = i; p <= j; p++) {
                        min_d = min(min_d, dp[k][path[p]]); // 计算点 k 到路径 F 的距离时，是在 F 的所有点中找距离 k 最小的
                    }
                    ecc = max(ecc, min_d);
                }
                ans = min(ans, ecc);
            }
        }
    }

    cout << ans;
    return 0;
}