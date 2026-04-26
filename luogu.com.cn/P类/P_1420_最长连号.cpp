#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, last = -1, cnt = 0, maxn = 1;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x - last == 1 || last == -1) {
            cnt++;
        } else {
            cnt = 1;
        }
        maxn = max(maxn, cnt);
        last = x;
    }
    cout << maxn;
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