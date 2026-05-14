#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << '\n';
#define IAK std::ios::sync_with_stdio(false);
#define IOI std::cin.tie(nullptr)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<long, long>;

const int N = 205;

int cur[N]; // 优化访问
int level[N]; // 分层dinic核心只让水流顺着走
vector<array<ll, 4>> g[N];

const ll inf = 0x3f3f3f3f3f3f3f3f;

bool bfs(int st, int target)
{
    memset(level, -1, sizeof level);
    queue<int> q;
    q.push(st);
    level[st] = 1; // 从1开始分层，0表示未访问

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto& edge : g[u]) {
            ll v = edge[0], w = edge[1];
            ll flow = edge[2]; // 这条水管目前流了多少水

            if (level[v] == -1 && w - flow > 0) { // 没访问过且还有剩余容量
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }

    return level[target] != -1; // 是否分层成功
}

ll dfs(int u, int target, ll minflow)
{
    if (minflow == 0)
        return 0;
    if (u == target)
        return minflow;

    for (int& i = cur[u]; i < g[u].size(); i++) {
        auto& edge = g[u][i];
        ll v = edge[0], w = edge[1];
        ll& flow = edge[2]; // 这条水管目前流了多少水
        ll rev = edge[3]; // 这条水的反向边编号

        // 核心判断分层，只能流向下一层还有得容纳
        if (level[u] + 1 != level[v] || w - flow <= 0)
            continue;

        // 最多只能推过去当前水和管道剩余容量中较小的那个值
        int newminflow = dfs(v, target, min(minflow, w - flow));
        if (newminflow == 0)
            continue;

        flow += newminflow;
        g[v][rev][2] -= newminflow; // 反向边流量减少

        return newminflow;
    }
    return 0;
}

ll dinic(int s, int t)
{
    ll flow = 0;
    while (bfs(s, t)) { // 分层成功
        memset(cur, 0, sizeof cur);
        while (ll tried = dfs(s, t, inf)) {
            flow += tried;
        }
    }

    return flow;
}

void solve()
{
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({ v, w, 0, (int)g[v].size() });
        g[v].push_back({ u, 0, 0, (int)g[u].size() - 1 });
    }
    cout << dinic(s, t);
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