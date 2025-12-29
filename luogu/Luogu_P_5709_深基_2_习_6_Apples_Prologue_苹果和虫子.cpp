#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int m, t, s;
    cin >> m >> t >> s;
    if (t == 0) cout << 0;
    else {
        if (m - (s + t - 1) / t <= 0) cout << 0;
        else cout << m - (s + t - 1) / t;
    }
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