#include<bits/stdc++.h>
#define int long long

using namespace std;

constexpr int N = 2e5 + 5;

void solve() {
    int maxn = 0, minn = INT_MAX, sum = 0, n, ans1 = INT_MIN, ans2 = INT_MAX;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        maxn = max(x, x + maxn);
        ans1 = max(ans1, maxn);
        sum += x;
        minn = min(x, x + minn);
        ans2 = min(ans2, minn);
    }
    if (sum - ans2 == 0) {
        cout << ans1;
    } else {
        cout << max(ans1, sum - ans2);
    }
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