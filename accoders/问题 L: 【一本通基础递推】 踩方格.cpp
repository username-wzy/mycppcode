#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> dp(25, vector<int>(25));
    dp[1][1] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i > 1)
                dp[i][j] += dp[i - 1][j];
            if (j > 1)
                dp[i][j] += dp[i][j - 1];
            if (j < n)
                dp[i][j] += dp[i][j + 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            
        }
    }
    return 0;
}