#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    map<int, int> mp;
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            for (int k = 1; k <= c; k++) {
                // if (i != j && i != k && j != k) {
                mp[i + j + k]++;
                // }
            }
        }
    } 
    int mx = 0, ans = 0;
    for (auto p : mp) {
        if (p.second > mx) {
            mx = p.second;
            ans = p.first;
        }
    }
    cout << ans;
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