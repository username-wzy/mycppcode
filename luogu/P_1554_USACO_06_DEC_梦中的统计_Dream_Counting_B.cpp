#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int m, n;
    cin >> m >> n;
    unordered_map<int, int> mp;
    for (int i = m; i <= n; i++) {
        int x = i;
        while (x) {
            mp[x % 10]++;
            x /= 10;
        }
    }
    for (int i = 0; i <= 9; i++) cout << mp[i] << " ";
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