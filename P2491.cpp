#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 300005;

struct Edge {
    int to, next, w;
} edge[N << 1];

int head[N], tot_edge;
int n, s;
ll d[N], dist[N];
int pre[N], path[N], cnt;
bool is_on_path[N];

void add(int u, int v, int w)
{
    edge[++tot_edge] = { v, head[u], w };
    head[u] = tot_edge;
}

// 第一次 DFS 找最远点，第二次找直径并记录前驱
void dfs_dist(int u, int fa)
{
    for (int i = head[u]; i; i = edge[i].next) {
        int v = edge[i].to;
        if (v == fa || is_on_path[v])
            continue;
        dist[v] = dist[u] + edge[i].w;
        pre[v] = u;
        dfs_dist(v, u);
    }
}

ll sum[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> s;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }

    // 1. 找直径
    int A = 1, B = 1;
    dist[A] = 0;
    dfs_dist(A, 0);
    for (int i = 1; i <= n; i++)
        if (dist[i] > dist[A])
            A = i;

    dist[A] = 0;
    pre[A] = 0;
    dfs_dist(A, 0);
    for (int i = 1; i <= n; i++)
        if (dist[i] > dist[B])
            B = i;

    // 2. 提取直径路径
    int curr = B;
    while (curr) {
        path[++cnt] = curr;
        is_on_path[curr] = true;
        curr = pre[curr];
    }
    reverse(path + 1, path + cnt + 1);

    sum[1] = 0;
    for (int i = 1; i <= cnt; i++) {
        sum[i] = dist[path[i]];
    }

    // 3. 计算直径上每个点往外延伸的最大深度
    ll max_d = 0;
    for (int i = 1; i <= cnt; i++) {
        int u = path[i];
        dist[u] = 0; // 重置该点，向非直径区域探索
        dfs_dist(u, 0);
    }

    for (int i = 1; i <= n; i++) {
        max_d = max(max_d, dist[i]);
    }

    // 4. 双指针滑动窗口
    ll ans = 2e18; // 足够大的初始值
    int r = 1;
    for (int l = 1; l <= cnt; l++) {
        // 滑动窗口：保证路径长度不超过 s
        while (r < cnt && sum[r + 1] - sum[l] <= s)
            r++;

        // 偏心距 = max(所有支链深度, 左端点距离, 右端点距离)
        ll res = max({ max_d, sum[l], sum[cnt] - sum[r] });
        ans = min(ans, res);
    }

    cout << ans << '\n';

    return 0;
}