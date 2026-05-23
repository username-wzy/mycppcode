#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << '\n';
#define IAK std::ios::sync_with_stdio(false);
#define IOI std::cin.tie(nullptr)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<long, long>;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<pii> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;
    vector<vector<pii>> g(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({ v, w });
        g[v].push_back({ u, w });
    }
    vector<array<int, 21>> dp(n + 1);
    priority_queue<pll> q;
    q.push({ 0, 1 });
    if (k == 0) {
    }

    int main()
    {
        IAK IOI;
        int T = 1;
        cin >> T;
        while (T--)
            solve();
        return 0;
    }