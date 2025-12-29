#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    string s = "", t;
    int k = 0;
    while (cin >> t) {
        s += t;
        k++;
    }
    cout << s.size() / k << " ";
    if (s[0] == '1') {
        cout << 0 << " ";
    }
    int cnt = 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) {
            cnt++;
        } else {
            cout << cnt << " ";
            cnt = 1;
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