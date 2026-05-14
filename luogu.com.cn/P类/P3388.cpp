#include <bits/stdc++.h>
#define debug(...) cerr << #__VA_ARGS__ << " = " << __VA_ARGS__ << endl;
#define IAK std::ios::sync_with_stdio(false);
#define IOI std::cin.tie(nullptr)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<long, long>;

const int MAXN = 2e4 + 5;

bool is_cut[MAXN];
int dfn[MAXN], low[MAXN]; // 记录某个节点是否为割点
int idx = 0;
vector<int> g[MAXN];

void dfs(int u, int fa)
{
    dfn[u] = low[u] = ++idx;
    int child_count = 0; // 用于统计 DFS 生成树中的子节点数量

    for (int v : g[u]) {
        if (!dfn[v]) {
            child_count++;
            dfs(v, u);
            low[u] = min(low[u], low[v]);

            // 割点判定逻辑
            if (u != fa && low[v] >= dfn[u]) {
                is_cut[u] = true; // 非根节点，且满足追溯值条件
            }
        } else if (v != fa) {
            low[u] = min(low[u], dfn[v]);
        }
    }

    // 处理树根的情况：如果是起点，且有两个及以上子树，则是割点
    // 这里的 fa 传入的是起点的编号，即 dfs(root, root)
    if (u == fa && child_count >= 2) {
        is_cut[u] = true;
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
    for (int i = 1; i <= n; i++) {
        if (!dfn[i])
            dfs(i, i);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (is_cut[i])
            ans++;
    }
    cout << ans << endl;
    for (int i = 1; i <= n; i++) {
        if (is_cut[i])
            cout << i << ' ';
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