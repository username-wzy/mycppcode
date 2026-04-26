#include<bits/stdc++.h>
#define ll long long

using namespace std;

int f[305], cnt[305];

void dfs(int x) {
    cnt[x]++;
    if (f[x] != x) dfs(f[x]);
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) cin >> f[i];
    int q; cin >> q;
    while (q--) {
        memset(cnt, 0, sizeof(cnt));
        int m; cin >> m;
        for (int i = 1; i <= m; i++) {
            int x;
            cin >> x;
            dfs(x);
        }
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (cnt[i] == m) {
                ans = i;
            }
        }
        cout << ans << '\n';
    }
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