/*
60 pts O(n n logn)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 2e4 + 5;
vector<pair<int, int>> g[N];
int fa[16][N], n;
int dep[N], dist[N];

void get_depth()
{
    queue<pair<int, int>> q;
    q.push({ 1, 0 });

    while (!q.empty()) {
        auto [u, fa] = q.front();
        q.pop();
        for (auto [v, w] : g[u]) {
            if (v == fa)
                continue;
            ::fa[0][v] = u;
            dep[v] = dep[u] + 1;
            dist[v] = dist[u] + w;
            q.push({ v, u });
        }
    }
}

void LCA_pre()
{
    for (int i = 1; i <= 15; i++)
        for (int u = 1; u <= n; u++)
            fa[i][u] = fa[i - 1][fa[i - 1][u]];
}

int get_lca(int u, int v)
{
    if (dep[u] < dep[v])
        swap(u, v);
    for (int i = 15; i >= 0; i--) {
        if (dep[fa[i][u]] >= dep[v])
            u = fa[i][u];
    }
    if (u == v)
        return u;
    for (int i = 15; i >= 0; i--) {
        if (fa[i][u] != fa[i][v]) {
            u = fa[i][u];
            v = fa[i][v];
        }
    }
    return fa[0][u];
}

ll query(int x, int y)
{
    return (ll)dist[x] + (ll)dist[y] - 2 * (dist[get_lca(x, y)]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({ v, w });
        g[v].push_back({ u, w });
    }

    get_depth();
    LCA_pre();

    int fz = n, fm = n * n;

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (query(i, j) % 3 == 0) {
                fz += 2;
            }
        }
    }

    int __gcd = gcd(fz, fm);

    cout << fz / __gcd << "/" << fm / __gcd;
    return 0;
}
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 2e5 + 5;

vector<pair<int, int>> g[N];
int dp[N][3];
int ans = 0;

void dfs(int u, int fa)
{
    for (auto [v, w] : g[u]) {
        if (v == fa)
            continue;
        dfs(v, u);
        // 1. 枚举u的余数与v的余数的所有组合
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if ((i + j + (w % 3)) % 3 == 0) {
                    ans += (ll)dp[u][i] * dp[v][j] * 2;
                }
            }
        }
        // 2. 将v的信息合并到u
        for (int i = 0; i < 3; i++) {
            dp[u][(i + (w % 3)) % 3] += dp[v][i];
        }
    }
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
    for (int i = 1; i <= n; i++) {
        dp[i][0] = 1;
    }
    dfs(1, 0);
    cout << (ans + n) / gcd(ans + n, n * n) << '/' << n * n / gcd(ans + n, n * n);
    return 0;
}