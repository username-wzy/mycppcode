#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << '\n';
#define IAK std::ios::sync_with_stdio(false);
#define IOI std::cin.tie(nullptr)

using namespace std;

/**
 * @File: P2016
 * @Author: wzy
 * @Date: 2026-06-07 17:20
 */

constexpr int N = 1505;

vector<int> g[N];
int dp[N][2];

void dfs(int u, int fa)
{
    dp[u][1] = 1;
    for (int v : g[u]) {
        if (v == fa)
            continue;
        dfs(v, u);
        dp[u][0] += dp[v][1];
        dp[u][1] += min(dp[v][0], dp[v][1]);
    }
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int u;
        cin >> u;
        int cnt;
        cin >> cnt;
        while (cnt--) {
            int v;
            cin >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }
    dfs(0, 1e9);

    cout << min(dp[0][0], dp[0][1]);
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