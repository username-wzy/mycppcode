#include<bits/stdc++.h>
#define ll long long

using namespace std;

int n, a[1000005];

void solve() {
    cin >> n;
    unordered_map<int, int> mp1, mp2;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mp2[a[i]]++;
    }
    int ans = 0;
    mp2[a[1]]--;
    mp1[a[1]]++;
    for (int j = 2; j <= n - 1; j++) {
        mp2[a[j]]--;
        if (a[j] % 2) {
            mp1[a[j]]++;
            continue;
        }
        ans += mp1[a[j] / 2] * mp2[a[j] * 3];
        mp1[a[j]]++;
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