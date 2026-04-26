#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

constexpr int N = 5e4 + 5;

pii a[N];
ll n, sum[N], cnt[N];

ll lowbit(ll x) {return x & -x;}

void add(int x, int d) {
    while (x <= N) {
        sum[x] += d;
        cnt[x]++;
        x += lowbit(x);
    }
}

pair<ll, ll> getsum(ll x) {
    ll res = 0, res2 = 0;
    while (x > 0) {
        res += sum[x];
        res2 += cnt[x];
        x -= lowbit(x);
    }
    return {res, res2};
}

void solve() {
    ll sum = 0, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;

    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
        auto p = getsum(a[i].second);
        // cerr << p.first << " " << p.second << '\n';
        // for (int j = 1; j <= 6; j++) {
            // cout << ::sum[j] << " ";
        // }
        // cout << '\n';
        ans += a[i].first * (sum - p.first - a[i].second 
                             * (i - 1 - p.second) + 
                             a[i].second * p.second -
                             p.first);
        add(a[i].second, a[i].second);
        sum += a[i].second;
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