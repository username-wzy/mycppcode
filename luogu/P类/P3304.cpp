#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

constexpr int N = 3e5 + 5;
vector<int> g[N];
int d[N];
int tot = 0;

int dfs(int u, int fa)
{
    int dist = 0, d1 = 0, d2 = 0; // dist: 当前节点到子树的最长距离，d1: 当前节点到子树的最长距离，d2: 当前节点到子树的次长距离
    for (int v : g[u]) {
        if (v == fa)
            continue;
        int d = dfs(v, u) + 1; // 当前节点到子树的距离
        dist = max(dist, d);
        if (d > d1) { // 更新最长距离和次长距离
            d2 = d1; // 更新次长距离
            d1 = d; // 更新最长距离
        } else if (d > d2)
            d2 = d; // 更新最长距离
    }
    tot = max(tot, d1 + d2);
    return dist;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s;
    cin >> n >> s;

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (!d[i]) {
            tot = 0;
            dfs(i, -1);
            d[i] = tot;
        }
    }

    return 0;
}