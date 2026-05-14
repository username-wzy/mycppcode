#include <bits/stdc++.h>
#define debug(...) cerr << #__VA_ARGS__ << " = " << __VA_ARGS__ << endl;
#define IAK std::ios::sync_with_stdio(false);
#define IOI std::cin.tie(nullptr)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<long, long>;

vector<int> g[int(6e3 + 5)];
ll dp[int(6e3 + 5)][2];
ll r[int(6e3 + 5)];
bool fa[int(6e3 + 5)];

void dfs(int u)
{
    dp[u][0] = 0;
    dp[u][1] = r[u];
    for (int v : g[u]) {
        dfs(v);
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> r[i];
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[v].push_back(u);
        fa[u] = true;
    }
    int root = 1;
    for (int i = 1; i <= n; i++)
        if (!fa[i]) {
            root = i;
            break;
        }
    dfs(root);
    cout << max(dp[root][0], dp[root][1]) << '\n';
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