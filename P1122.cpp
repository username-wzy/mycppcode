#include <bits/stdc++.h>

using namespace std;

/*
1. 树
2. 连通
3. 求这个树的所有子树的点权合，子树不为空

思路dp，定义为以i为子树的根的最大子树和
显然初始值就包含自己也就是a[i]
dp[u] = a[u] + \sum_{i=1}^{g[u].size()} max(0, dp[v_i]);
就是自己加上自己的子节点（但是如果是非负数就不要）
*/

const int N = 16005;

int a[N], dp[N];
vector<int> g[N];

void dfs(int u, int fa)
{
    dp[u] = a[u];
    for (int v : g[u]) {
        if (v == fa)
            continue;
        dfs(v, u);
        dp[u] += max(0, dp[v]);
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    cout << *max_element(dp + 1, dp + 1 + n);
}