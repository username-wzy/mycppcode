#include<bits/stdc++.h>
#define int long long

using namespace std;

vector<pair<int, int>> a;
vector<int> dp;

void solve() {
    int n, L, sum = 0;
    cin >> n >> L;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
        sum += a[i].second;
        a[i].second = min(L, a[i].second);
    }
    dp.resize(2 * L + 50, INT_MAX);
    if (sum < L) {
        cout << "no solution";
        return ;
    }
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 2 * L; j >= a[i].second; j--) {
            dp[j] = min(dp[j],dp[j - a[i].second] + a[i].first);
        }
    }
    int minn = INT_MAX;
    for (int i = L; i <= 2 * L; i++) {
        minn = min(minn, dp[i]);
    }
    cout << minn;
}

signed main() {
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