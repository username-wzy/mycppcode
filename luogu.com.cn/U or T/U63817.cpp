#include<bits/stdc++.h>
#define ll long long

using namespace std;

pair<int, int> a[1005];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i].second;
    }
    sort(a + 1, a + 1 + n, [](pair<int, int> x, pair<int, int> y) {
        return min(x.first, y.second) < min(y.first, x.second);
    });
    int ta = 0, tb = 0;
    for (int i = 1; i <= n; i++) {
        ta += a[i].first;
        tb = max(tb, ta) + a[i].second;
    }
    cout << tb;
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