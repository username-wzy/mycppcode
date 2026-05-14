#include <bits/stdc++.h>
#define debug(...) cerr << #__VA_ARGS__ << " = " << __VA_ARGS__ << endl;
#define IAK std::ios::sync_with_stdio(false);
#define IOI std::cin.tie(nullptr)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<long, long>;

const int N = 5005;

int cur[N]; // 优化访问
int level[N]; // 分层dinic核心只让水流顺着走
int n, m, t;
vector<vector<array<int, 4>>> g, g2;
const int inf = 0x3f3f3f;

bool bfs(int u, int target)
{
    memset(level, -1, sizeof level);
    queue<int> q;
    q.push(u);
    level[u] = 1; // 从1开始分层，0表示未访问

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto& edge : g[u]) {
            int v = edge[0], w = edge[1];
            int flow = edge[2]; // 这条水管目前流了多少水

            if (level[v] == -1 && w - flow > 0) { // 没访问过且还有剩余容量
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }

    return level[target] != -1; // 是否分层成功
}

int dfs(int u, int target, int minflow)
{
    if (minflow == 0)
        return 0;
    if (u == target)
        return minflow;

    for (int& i = cur[u]; i < g[u].size(); i++) {
        auto& edge = g[u][i];
        int v = edge[0], w = edge[1];
        int& flow = edge[2]; // 这条水管目前流了多少水
        int rev = edge[3]; // 这条水的反向边编号

        // 核心判断分层，只能流向下一层还有得容纳
        if (level[u] + 1 != level[v] || w - flow <= 0)
            continue;

        // 最多只能推过去当前水和管道剩余容量中较小的那个值
        int newminflow = dfs(v, target, min(minflow, w - flow));

        if (newminflow > 0) {
            flow += newminflow; // 增加正向流量
            g[v][rev][2] -= newminflow; // 减少反向流量（增加后悔空间）
            return newminflow;
        }
    }
    return 0;
}

int dinic(int s, int t)
{
    int flow = 0;
    memset(level, 0, sizeof level);
    while (bfs(s, t)) { // 分层成功
        memset(cur, 0, sizeof cur);
        while (int tried = dfs(s, t, inf)) {
            flow += tried;
        }
    }

    return flow;
}

void add(int u, int v, int w)
{
    g[u].push_back({ v, w, 0, (int)g[v].size() });
    g[v].push_back({ u, 0, 0, (int)g[u].size() - 1 });
}

bool check(int mid)
{
    g.clear();
    g.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        for (auto p : g2[i]) {
            if (p[1] <= mid && p[1] > 0) {
                add(i, p[0], 1);
                add(p[0], i, 1);
            }
        }
    }

    return dinic(1, n) >= t;
}

void solve()
{
    cin >> n >> m >> t;
    int r = 0;
    g2.resize(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        r = max(r, w);
        g2[u].push_back({ v, w, 0, (int)g2[v].size() });
        g2[v].push_back({ u, 0, 0, (int)g2[u].size() - 1 });
    }

    int l = 0, ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << ans;
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