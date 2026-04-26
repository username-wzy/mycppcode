#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll mp[129][2];

void solve() {
    ll p, cnt = 0;
    cin >> p;
    char c;
    bool flag = 0;
    while (cin >> c) {
        int x = c - '0';
        for (int i = 0; i <= p - 1; i++) {
            mp[(i * 10 + x) % p][flag] += mp[i][!flag];
        }
        mp[x % p][flag]++;
        cnt += mp[0][flag];
        for (int i = 0; i <= p - 1; i++) {
            mp[i][!flag] = 0;
        }
        flag ^= 1;
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