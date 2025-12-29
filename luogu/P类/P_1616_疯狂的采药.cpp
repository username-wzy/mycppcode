#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int n, W;   
    cin >> W >> n;
    vector<int> w(n + 1), v(n + 1);
    vector<int> dp(W + 1);
    for (int i = 1; i <= n; i++) 
        cin >> w[i] >> v[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            if (j < w[i]) {
                dp[j] = dp[j];
            } else dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[W];
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	while (T--) {
		solve();
	}
	return 0;
}