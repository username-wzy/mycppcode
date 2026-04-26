#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int s, v;
    cin >> s >> v;
    int cnt = 10;
    cnt += (s + v - 1) / v;
    int hh = 8 - cnt / 60;
    if (cnt % 60 != 0) hh--;
    while (hh < 0) {
        hh += 24;
    }
    int ss = 60 - cnt % 60;
    if (ss == 60) {
        ss = 0;
    }
    if (hh < 10) {
        cout << 0;
    }
    cout << hh << ':';
    if (ss < 10) cout << '0';
    cout << ss;
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