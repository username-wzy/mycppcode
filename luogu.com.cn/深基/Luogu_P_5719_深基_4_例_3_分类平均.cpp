#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    int s1 = 0, s2 = 0, c1 = 0, c2 = 0;
    for (int i = 1; i <= n; i++) {
        if (i % k == 0) s1 += i, c1++;
        else s2 += i, c2++;
    }
    cout << fixed << setprecision(1) << s1 * 1.0 / c1 << " " << s2 * 1.0 / c2;
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