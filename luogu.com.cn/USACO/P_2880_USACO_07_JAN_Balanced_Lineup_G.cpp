#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 5e4 + 5;

int bit1[N], bit2[N], n, m, a[N];

int lowbit(int x) {
    return x & -x;
}

void add(int x, int d) {
    while (x <= n) {
        bit1[x] = max(bit1[x], d);
        bit2[x] = min(bit2[x], d);
        x += lowbit(x);
    }
}

pair<int, int> mx(int l, int r) {
    int res = 0, res2 = INT_MAX;
    while (l <= r) {
        if (r - lowbit(r) < l) {
            res = max(res, a[r]);
            res2 = min(res2, a[r]);
            r--;
        } else {
            res = max(res, bit1[r]);
            res2 = min(res2, bit2[r]);
            r -= lowbit(r);
        }
    }
    return {res, res2};
}

void solve() {
    memset(bit2, 0x7f, sizeof(bit2));
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        add(i, a[i]);
    }
    while (m--) {
        int l, r;
        cin >> l >> r;
        auto p = mx(l, r);
        cout << p.first - p.second << '\n';
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