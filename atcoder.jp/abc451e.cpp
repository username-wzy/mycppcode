#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct edge {
    int u, v, w;
};

int fa[3005];
vector<pair<int, int>> g[3005];
int graph[3005][3005];
int vis[3005], dist[3005];

int find(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}

bool unite(int x, int y)
{
    int root_x = find(x);
    int root_y = find(y);
    if (root_x != root_y) {
        fa[root_x] = root_y;
        return true;
    }
    return false;
}

void dfs(int u, int cnt)
{
    vis[u] = 1;
    dist[u] = cnt;
    for (auto [v, w] : g[u]) {
        if (!vis[v]) {
            dfs(v, cnt + w);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<edge> E;

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int w;
            cin >> w;
            graph[i][j] = graph[j][i] = w;
            E.push_back({ i, j, w });
        }
    }
    sort(E.begin(), E.end(), [](edge& a, edge& b) {
        return a.w < b.w;
    });

    for (int idx = 1; idx <= n; ++idx) {
        fa[idx] = idx;
    }

    ll mst_w = 0; // 生成树权重
    int edges_cnt = 0; // 生成树边数

    for (auto [u, v, w] : E) {
        if (unite(u, v)) {
            g[u].push_back({ v, w });
            g[v].push_back({ u, w });
            mst_w += w; // 加入边 e 后，生成树权重增加 e.w
            edges_cnt++; // 生成树边数增加 1
            if (edges_cnt == n - 1) // 生成树边数为节点数减一，说明生成树已形成
                break;
        }
    }

    if (edges_cnt == n - 1) {
        for (int i = 1; i <= n; i++) {
            memset(vis, 0, sizeof vis);
            memset(dist, 0, sizeof dist);
            dfs(i, 0);
            for (int j = 1; j <= n; j++) {
                if (j == i)
                    continue;
                if (dist[j] != graph[i][j]) {
                    cout << "No";
                    return 0;
                }
            }
        }
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}