#include<bits/stdc++.h>
#define ll long long

using namespace std;

int a[15], n, ans[15];

void solve() {
    // int a[15], n, ans[15];
    cin >> n;
    for (int i = 1; i <= 7; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        int id = 0;
        for (int j = 1; j <= 7; j++) {
            int x;
            cin >> x;
            for (int k = 1; k <= 7; k++) {
                if (x == a[k]) {
                    id++;
                    break;
                }
            }
        }
        ans[id]++;
    }
    for (int i = 7; i >= 1; i--) cout << ans[i] << " ";
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