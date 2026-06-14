#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << '\n';
#define IAK std::ios::sync_with_stdio(false);
#define IOI std::cin.tie(nullptr)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<long, long>;

const ll inf = 1e18;

void solve()
{
    int n, W;
    cin >> n >> W;
    vector<pll> items(n + 1);
    ll sumV = 0;
    for (int i = 1; i <= n; i++) {
        cin >> items[i].first >> items[i].second;
        sumV += items[i].second;
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(sumV + 1, inf));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (ll j = 0; j <= sumV; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= items[i].second)
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - items[i].second] + items[i].first);
        }
    }
    ll ans = 0;
    for (ll j = sumV; j >= 0; j--) {
        if (dp[n][j] <= W) {
            ans = j;
            break;
        }
    }
    cout << ans << '\n';
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