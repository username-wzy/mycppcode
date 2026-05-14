#include <bits/stdc++.h>
#define debug(...) cerr << #__VA_ARGS__ << " = " << __VA_ARGS__ << endl;
#define IAK std::ios::sync_with_stdio(false);
#define IOI std::cin.tie(nullptr)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<long, long>;

int low[155], dfn[155];
vector<int> g[155];
int idx = 0;
vector<pii> bridge;

void dfs(int u, int fa)
{
    // 1. 初始化：刚访问节点 u 时，其时间戳和追溯值均设为当前计数器 idx 的值
    dfn[u] = low[u] = ++idx;

    // 2. 遍历节点 u 的所有邻接点 v
    for (int v : g[u]) {
        if (!dfn[v]) {
            // 3. 树边处理：如果 v 尚未被访问，说明 (u, v) 是一条 DFS 生成树上的“树边”
            dfs(v, u); // 继续向下深度优先搜索

            // 4. 回溯更新：子节点 v 的搜索完成后，用 v 的 low 值更新 u 的 low 值。
            // 因为 v 能到达的最早节点，u 显然也能通过 v 到达。
            low[u] = min(low[u], low[v]);

            // 5. 割边判定核心逻辑
            if (low[v] > dfn[u]) {
                bridge.push_back({ u, v });
            }
        } else if (v != fa) {
            // 6. 返祖边处理：如果 v 已经被访问过，且 v 不是 u 的父节点 fa
            // 说明 (u, v) 是一条“返祖边”，这形成了一个环！
            // 此时我们用 v 的时间戳来更新 u 的追溯值
            low[u] = min(low[u], dfn[v]);
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 1);

    sort(bridge.begin(), bridge.end());

    for (auto [u, v] : bridge) {
        cout << u << ' ' << v << endl;
    }
}

int main()
{
    IAK IOI;
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}