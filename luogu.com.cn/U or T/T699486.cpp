#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int r;
    cin >> r;

    vector<vector<int>> a(r + 1, vector<int>(r + 1, 0));
    vector<vector<int>> dp(r + 1, vector<int>(r + 1, 0));

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> a[i][j];
        }
    }

    for (int j = 1; j <= r; ++j) {
        dp[r][j] = a[r][j];
    }

    for (int i = r - 1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + a[i][j];
        }
    }

    cout << dp[1][1] << "\n";

    return 0;
}