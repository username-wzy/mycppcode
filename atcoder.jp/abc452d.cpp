#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 2e5 + 5;

int dp[N][30];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;

    int n = s.size();

    for (int j = 0; j < 26; j++) {
        dp[n][j] = n; // 初始化为n，表示不存在该字符的位置
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            dp[i][j] = dp[i + 1][j]; // 先继承后面的结果
        }
        dp[i][s[i] - 'a'] = i; // 更新当前字符的位置
    }

    ll ans = 0;

    for (int l = 0; l < n; l++) {
        int p = l;
        bool ok = true;
        for (int k = 0; k < t.size(); k++) {
            if (p >= n || dp[p][t[k] - 'a'] == n) { // 如果p已经超出s的范围，或者t[k]在s中不存在
                ok = false; // 无法匹配
                break;
            }
            p = dp[p][t[k] - 'a'] + 1; // 更新p到下一个位置，继续匹配t的下一个字符
        }

        if (ok) {
            ans += (p - 1 - l); // 匹配成功，合法范围是 [l, p-2]
        } else {
            ans += (n - l); // 匹配失败，就是n-l
        }
    }
    cout << ans << '\n';
    return 0;
}