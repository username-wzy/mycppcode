#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct edge {
    int u, v, w;
};

int fa[200005];

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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<edge> edges(m);
    for (int idx = 0; idx < m; ++idx) {
        cin >> edges[idx].u >> edges[idx].v >> edges[idx].w;
    }

    sort(edges.begin(), edges.end(), [](edge& a, edge& b) {
        return a.w < b.w;
    });

    for (int idx = 1; idx <= n; ++idx) {
        fa[idx] = idx;
    }

    ll mst_w = 0; // 生成树权重
    int edges_cnt = 0; // 生成树边数

    for (auto e : edges) {
        if (unite(e.u, e.v)) {
            mst_w += e.w; // 加入边 e 后，生成树权重增加 e.w
            edges_cnt++; // 生成树边数增加 1
            if (edges_cnt == n - 1) // 生成树边数为节点数减一，说明生成树已形成
                break;
        }
    }

    if (edges_cnt == n - 1) {
        cout << mst_w << endl;
    } else {
        cout << "Disconnected" << endl;
    }

    return 0;
}