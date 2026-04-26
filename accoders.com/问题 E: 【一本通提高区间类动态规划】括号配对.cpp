#include <cstring>
#include <iostream>

std::string s;
int dp[5050][5050]; // dp[l][r] 表示 s[l..r] 最少需要添加多少个括号才能配对

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);

    // O(n ^ 2)
    std::cin >> s;
    s = " " + s;
    std::memset(dp, 0x3f, sizeof(dp));
    int n = s.size() - 1;
    for (int i = 1; i <= n; i++) {
        dp[i + 1][i] = 0;
        dp[i][i] = 1;
    }

    for (int len = 2; len <= n; len++) {
        for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;

            if ((s[l] == '(' && s[r] == ')')
                || (s[l] == '[' && s[r] == ']')) // 如果 s[l] 和 s[r] 可以配对
                dp[l][r] = dp[l + 1][r - 1]; // 就可以直接配对，不需要添加任何括号
            for (int k = l; k < r; k++) {
                dp[l][r] = std::min(dp[l][r], dp[l][k] + dp[k + 1][r]); // 否则，就需要在 s[l..k] 和 s[k+1..r] 之间添加括号
            }
        }
    }
    std::cout << dp[1][n];
    return 0;
}