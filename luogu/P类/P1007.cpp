#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int l, n, minn = 0, maxn = 0;
    cin >> l >> n;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        minn = max(minn, min(x, l + 1 - x));
        maxn = max(maxn, max(x, l + 1 - x));
    }
    cout << minn << " " << maxn;
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