#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int a[11];
    for (int i = 1; i <= 10; i++) cin >> a[i];
    int k, cnt = 0;
    cin >> k;
    for (int i = 1; i <= 10; i++) {
        if (k + 30 >= a[i]) cnt++;
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