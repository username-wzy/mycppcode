#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    map<pair<int, int>, bool> mp;
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        for (int j = x - 2; j <= x + 2; j++) {
            mp[{j, y}] = true;
        }
        for (int j = y - 2; j <= y + 2; j++) {
            mp[{x, j}] = true;
        }
        mp[{x - 1, y - 1}] = true;
        mp[{x - 1, y + 1}] = true;
        mp[{x + 1, y - 1}] = true;
        mp[{x + 1, y + 1}] = true;
    }
    for (int i = 1; i <= k; i++) {
        int x, y;
        cin >> x >> y;
        for (int j = x - 2; j <= x + 2; j++) {
            for (int k = y - 2; k <= y + 2; k++) {
                mp[{j, k}] = true;
            }
        }
    }
    // for (auto p : mp) {
    //     cerr << p.first.first << " " << p.first.second << ' ' << p.second << "\n";
    // }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!mp[{i, j}]) cnt++;
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