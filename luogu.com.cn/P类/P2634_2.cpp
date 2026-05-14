#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << '\n';
#define IAK std::ios::sync_with_stdio(false);
#define IOI std::cin.tie(nullptr)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<long, long>;

const int N = 2e4 + 5;

vector<pii> g[N];
int dp[N][3], ans;

void dfs(int u, int fa)
{
    dp[u][0] = 1;
    for (auto [v, w] : g[u]) {
        if (v == fa)
            continue;

        dfs(v, u);

        for (int i = 0; i < 3; i++) { // 找到能和dp[v][i]匹配的
            ans += dp[v][i] * dp[u][(3 - (w + i) % 3) % 3] * 2; // u -> v, v -> u, * 2
        }

        for (int i = 0; i < 3; i++) { // 更新当前
            dp[u][(w + i) % 3] += dp[v][i];
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({ v, w });
        g[v].push_back({ u, w });
    }

    ans = n; // 初始自己到自己0 % 3 == 0所以有n个
    dfs(1, 0);

    const int ans2 = n * n, gcd = __gcd(ans, ans2);

    cout << ans / gcd << "/" << ans2 / gcd;
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