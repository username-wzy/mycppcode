#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) (x & -x)

using namespace std;

ll t[1000005], n, m, vis[1000005];
pair<ll, ll> a[1000005];

void add(ll x, ll d) {
    for (int i = x; i <= n + m; i += lowbit(i)) {
        t[i] += d;
    }
}

ll sum(int x) {
    ll res = 0;
    for (int i = x; i > 0; i -= lowbit(i)) {
        res += t[i];
    }
    return res;
}

void solve() {
    cin >> n >> m;
    for (int i = n; i >= 1; i--) {
        cin >> a[i].first;
        a[i].second = i;
        add(i, 1);
    }
    for (int i = n + 1; i <= n + m; i++) {
        cin >> a[i].first;
        a[i].second = i;
        add(i, 1);
    }
    sort(a + 1, a + n + m + 1, greater<pair<int, int>>());
    ll l = n, r = l + 1, ans = 0;
    for (int i = 1; i <= n + m; i++) {
        if (a[i].second >= r) { // a[i].second是删掉数的下表
            ans += sum(a[i].second) - sum(r);
            if (vis[r]) ans--;
            add(a[i].second, -1);
            vis[a[i].second] = 1;
            r = a[i].second;
            l = a[i].second - 1;
        } else {
            ans += sum(l) - sum(a[i].second);
            add(a[i].second, -1);
            vis[a[i].second] = 1;
            l = a[i].second;
            r = a[i].second + 1;
        }
        // cerr << a[i].second << " " << ans << "\n";
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