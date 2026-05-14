#include <bits/stdc++.h>
#define debug(...) cerr << #__VA_ARGS__ << " = " << __VA_ARGS__ << endl;
#define IAK std::ios::sync_with_stdio(false);
#define IOI std::cin.tie(nullptr)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<long, long>;

const int N = 55;

int dp[N][N][4][2];

void solve()
{
    int n, K;
    cin >> n >> K;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    memset(dp, 0, sizeof dp);
    if (n > 1 && a[1][0] == '.')
        dp[2][1][0][0] = 1;
    if (n > 1 && a[0][1] == '.')
        dp[1][2][0][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1][j - 1] == '#' || (i == 1 && j == 1))
                continue;
            for (int k = 0; k <= K; k++) {
                if (i > 1) {
                    dp[i][j][k][0] += dp[i - 1][j][k][0];
                    if (k > 0)
                        dp[i][j][k][0] += dp[i - 1][j][k - 1][1];
                }
                if (j > 1) {
                    dp[i][j][k][1] += dp[i][j - 1][k][1];
                    if (k > 0)
                        dp[i][j][k][1] += dp[i][j - 1][k - 1][0];
                }
            }
        }
    }
    long long ans = 0;
    for (int k = 0; k <= K; k++) {
        ans += dp[n][n][k][0] + dp[n][n][k][1];
    }
    cout << ans << '\n';
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