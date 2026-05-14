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
    int n, W;
    cin >> n >> W;
    vector<pll> items(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> items[i].first >> items[i].second;
    vector<ll> dp(W + 1, 0);
    for (int i = 1; i <= n; i++)
        for (ll w = W; w >= items[i].first; w--)
            dp[w] = max(dp[w], dp[w - items[i].first] + items[i].second);
    cout << dp[W] << '\n';
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