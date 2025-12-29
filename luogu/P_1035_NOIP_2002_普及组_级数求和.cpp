#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, cnt = 0;
    long double d;
    cin >> n;
    for (int i = 1; ; i++) {
        d += 1.0 / i;
        cnt++;
        if (d > n) {
            break;
        }
    }
    cout << cnt;
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