#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int x, cnt = 0, m = 0;
    for (int i = 1; i <= 12; i++) {
        cin >> x;
        m += 300 - x;
        if (m < 0) {
            cout << '-' << i;
            return ;
        }
        while (m >= 100) {
            cnt += 100;
            m -= 100;
        }
    }
    cout << cnt * 1.2 + m;
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