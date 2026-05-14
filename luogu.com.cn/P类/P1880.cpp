#include <bits/stdc++.h>
#define debug(...) cerr << #__VA_ARGS__ << " = " << __VA_ARGS__ << endl;
#define IAK std::ios::sync_with_stdio(false);
#define IOI std::cin.tie(nullptr)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<long, long>;

constexpr int inf = 0x3f3f3f3f;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(2 * n + 2), s(2 * n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    for (int i = 1; i <= 2 * n; i++)
        s[i] = s[i - 1] + a[i];

    auto fuck = [&] {
        vector<vector<int>> dp(2 * n + 2, vector<int>(2 * n + 2, inf));
        for (int i = 1; i <= n * 2; i++)
            dp[i][i] = 0;
        for (int len = 2; len <= n; len++) {
            for (int l = 1; l + len - 1 <= 2 * n; l++) {
                const int r = l + len - 1;
                for (int k = l; k < r; k++)
                    dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + s[r] - s[l - 1]);
            }
        }
        int ans = inf;
        for (int i = 1; i <= n; i++) {
            ans = min(ans, dp[i][i + n - 1]);
        }
        cout << ans << '\n';
    };
    auto fuck2 = [&] {
        vector<vector<int>> dp(2 * n + 2, vector<int>(2 * n + 2, 0));
        for (int len = 2; len <= n; len++) {
            for (int l = 1; l + len - 1 <= 2 * n; l++) {
                const int r = l + len - 1;
                for (int k = l; k < r; k++)
                    dp[l][r] = max(dp[l][r], dp[l][k] + dp[k + 1][r] + s[r] - s[l - 1]);
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, dp[i][i + n - 1]);
        }
        cout << ans << '\n';
    };
    fuck();
    fuck2();
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