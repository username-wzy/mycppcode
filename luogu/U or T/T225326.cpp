#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

constexpr int N = 1000005;

vector<pair<int, int>> g[N];
int c[N], ans = 0;

int dfs(int u, int fa)
{
    int dist = 0, d1 = 0, d2 = 0; // dist: 当前节点到子树的最长距离，d1: 当前节点到子树的最长距离，d2: 当前节点到子树的次长距离
    for (auto [v, w] : g[u]) {
        if (v == fa)
            continue;
        int d = dfs(v, u) + w; // 当前节点到子树的距离
        dist = max(dist, d);
        if (d > d1) { // 更新最长距离和次长距离
            d2 = d1; // 更新次长距离
            d1 = d; // 更新最长距离
        } else if (d > d2) { // 更新次长距离
            d2 = d;
        }
    }
    ans = max(ans, d1 + d2);
    return dist;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({ v, w });
        g[v].push_back({ u, w });
    }
    dfs(1, -1);
    cout << ans;
    return 0;
}