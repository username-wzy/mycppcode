#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, sum = 0;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    int l, r;
    cin >> l >> r;
    if (sum < n * l || sum > n * r) {
        cout << -1;
        return ;
    }
    int in, out;
    in = out = 0;
    for (int i = 1; i <= n; i++) {
        in += max(0, a[i] - r);
        out += max(0, l - a[i]);
    }
    cout << max(in, out);
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