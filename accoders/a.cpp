#include <iostream>
#include <string>
int n, dp[5050][5050];

std::string s;

int main()
{
    std::cin >> s;
    const int n = s.size();
    s = " " + s;
    for (int i = 1; i <= n; i++) {
        dp[i + 1][i] = 0;
        dp[i][i] = 1;
    }
    for (int len = 2; len <= n; len++) {
        for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            if (s[l] == s[r])
                dp[l][r] = dp[l + 1][r - 1];
            
            }
    }
}