#include<bits/stdc++.h>
#define ll long long

using namespace std;

struct node {
    int x, y;
};

void solve() {
    int n, cnt = 0;
    cin >> n;
    vector<int> a(n);
    unordered_map<int, bool> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]] = 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (mp[a[i] + a[j]]) {
                cnt++;
                mp[a[i] + a[j]] = 0;
            }
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