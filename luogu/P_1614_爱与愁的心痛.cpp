#include<bits/stdc++.h>
#define ll long long

using namespace std;

int a[30000], s[30000];

void solve() {
    int n, m, mx = INT_MAX;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    for (int i = m; i <= n; i++) {
        mx = min(mx, s[i] - s[i - m]);
    }
    cout << mx;
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