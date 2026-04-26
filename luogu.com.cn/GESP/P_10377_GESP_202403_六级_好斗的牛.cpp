#include<bits/stdc++.h>
#define ll long long
#define px p.first
#define py p.second

using namespace std;

pair<int, int> a[15];
int mx = 1e9, n, vis[15];

void dfs(int x, int step, int last) {
    if (x == n + 1) {
        mx = min(mx, step);
        return ;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            int y = max(a[last].second, a[i].first) + step + 1;
            if (x == 1) y = 1;
            dfs(x + 1, y, i);
            vis[i] = 0;
        }
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i].second;
    }
    dfs(1, 0, 0);
    cout << mx << "\n";
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