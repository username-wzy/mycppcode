#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << '\n';
#define IAK std::ios::sync_with_stdio(false);
#define IOI std::cin.tie(nullptr)

using namespace std;

/**
 * @File: P2279
 * @Author: wzy
 * @Date: 2026-06-07 18:16
 */

constexpr int N = 1e3 + 5;

vector<int> g[N];
int dp[N][5];

void dfs(int u, int fa)
{
    int sum_dp4 = 0, sum_dp2 = 0, sum_dp3 = 0;
    for (int v : g[u]) {
        if (v == fa)
            continue;
        dfs(v, u);
        sum_dp4 += dp[v][4];
        sum_dp2 += dp[v][2];
        sum_dp3 += dp[v][3];
    }
    dp[u][0] = 1 + sum_dp4;
    dp[u][3] = sum_dp2;
    dp[u][4] = sum_dp3;
    dp[u][1] = dp[u][2] = 1e9;
    for (int v : g[u]) {
        if (v == fa)
            continue;
        dp[u][1] = min(dp[u][1], dp[v][0] + sum_dp3 - dp[v][1]);
        dp[u][2] = min(dp[u][2], dp[v][1] + sum_dp2 - dp[v][2]);
    }
    dp[u][1] = min(dp[u][1], dp[u][0]);
    dp[u][2] = min(dp[u][2], dp[u][1]);
    dp[u][3] = min(dp[u][3], dp[u][2]);
    dp[u][4] = min(dp[u][4], dp[u][3]);
}

void solve()
{
    int n;
    cin >> n;
    for (int u = 2; u <= n; u++) {
        int v;
        cin >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0);

    cout << dp[1][2];
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