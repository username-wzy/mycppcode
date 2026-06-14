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
    int n;
    cin >> n;

    vector<ll> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];

    vector<ll> dp(n + 2);
    for (int i = n; i >= 1; i--) {
        const int nxt = b[i] + i;
        dp[i] = max(dp[i + 1], a[i]);
        if (b[i] == 0)
            dp[i] = max(dp[i], dp[i + 1] + a[i]);
        else if (nxt <= n)
            dp[i] = max(dp[i + 1], a[i] + dp[nxt]);
    }
    cout << dp[1] << '\n';
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