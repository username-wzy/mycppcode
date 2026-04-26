#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll l = 1, r = 1e9, op;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        cout << mid << endl;
        cin >> op;
        if (op == 0) return ;
        else if (op == -1) l = mid + 1;
        else r = mid - 1;
    }
}

int main() {

    // freopen("xxx.in", "r", stdin);
    // freopen("xxx.out", "w", stdout);

    int T = 1; // cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}