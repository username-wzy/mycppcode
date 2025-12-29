#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll n, x, t = 0;
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        char c; cin >> c;
        if (c == 'U') {
            if (x == 1) continue;
            if (t >= 1) t--;
            else x /= 2;
        } else if (c == 'L') {
            if (x * 2 >= 1e12) {
                t++;
            } else x *= 2;
        } else {
            if (x * 2 + 1 > 1e12) t++;
            else x = x * 2 + 1;
        }
    }
    cout << x;
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