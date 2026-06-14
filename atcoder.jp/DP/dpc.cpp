#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << '\n';
#define IAK std::ios::sync_with_stdio(false);
#define IOI std::cin.tie(nullptr)
#define vec vector
#define vin vector<int>
#define arr array
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<long, long>;

const int inf = 1e9;

void solve()
{
    int n;
    cin >> n;
    vec<arr<int, 3>> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    vec<arr<int, 3>> dp(n + 1);
    dp[1] = { a[1][0], a[1][1], a[1][2] };
    for (int i = 2; i <= n; i++) {
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + a[i][0];
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + a[i][1];
        dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + a[i][2];
    }
    cout << max(dp[n][0], max(dp[n][1], dp[n][2])) << '\n';
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