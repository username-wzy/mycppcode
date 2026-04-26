#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        dp[i] = i;      // 最差情况就是全是1
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j * j <= i; j++) { // 枚举可以的平方数
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
    cout << dp[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // freopen("xxx.in", "r", stdin);
    // freopen("xxx.out", "w", stdout);

    int T = 1; // cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}