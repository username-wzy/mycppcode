#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

constexpr int N = 1005;

ll dp[N][3][N]; // i, k, j 表示在以i为结尾，出了牌k，换了j个
int a[N], b[N], c[N];

int win(int x, int y)
{
    if ((x + 1) % 3 == y)
        return 0;
    if (x == y)
        return 1;
    return 2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++) {
        cin >> b[i];
        b[i] += b[i - 1];
    }
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < i; k++) {
                dp[i][j][k] = dp[i - 1][j][k] + win(j, c[i]) * a[i];
                if (k > 0) {
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][(j + 1) % 3][k - 1] + win(j, c[i]) * a[i]);
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][(j + 2) % 3][k - 1] + win(j, c[i]) * a[i]);
                }
            }
        }
    }
    ll ans = INT_MIN;
    for (int j = 0; j <= 2; j++)
        for (int k = 0; k < n; k++)
            ans = max(ans, dp[n][j][k] - b[k]);
    cout << ans;
    return 0;
}