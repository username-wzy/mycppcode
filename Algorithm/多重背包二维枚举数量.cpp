#include<bits/stdc++.h>
#define ll long long

using namespace std;

int n, W, w[105], v[105], amount[105], dp[105][20000];

void solve() {
    int n, W;
    cin >> n >> W;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i] >> amount[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            for (int k = 0; k <= amount[i] && k * w[i] <= j; k++) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k * w[i]] + k * v[i]);
            }
        }
    }
    cout << dp[n][W] << '\n';
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