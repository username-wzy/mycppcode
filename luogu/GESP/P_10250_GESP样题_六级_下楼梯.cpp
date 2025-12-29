#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll n, a[80];
    cin >> n;
    a[1] = 1;
    a[2] = 2;
    a[3] = 4;
    for (int i = 4; i <= n; i++) {
        a[i] = a[i - 1] + a[i - 2] + a[i - 3];
    }
    cout << a[n] << "\n";
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