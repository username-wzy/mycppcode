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
    int n, K;
    cin >> n >> K;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> dp(n, 0x3f3f3f3f);
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        for (int k = 1; k <= K && i - k >= 0; k++)
            dp[i] = min(dp[i - k] + abs(a[i - k] - a[i]), dp[i]);
    }
    for (int i = 0; i < n; i++)
        debug(dp[i]);
    cout << dp[n - 1] << '\n';
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