#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    double d, loss = 1;
    int cnt = 0;
    cin >> d;
    while (d > 0) {
        cnt++;
        d -= 2 * loss;
        loss *= 0.98;
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