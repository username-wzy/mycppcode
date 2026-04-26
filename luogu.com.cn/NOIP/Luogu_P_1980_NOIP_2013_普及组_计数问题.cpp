#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, x, cnt = 0;
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        string s = to_string(i);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0' + x) cnt++;
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