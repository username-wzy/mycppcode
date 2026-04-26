#include<bits/stdc++.h>
#define ll long long

using namespace std;

constexpr int N = 5e5 + 5;

int a[N], bit[N], n, m;

int lowbit(int x) {
    return x & -x;
}

void add(int x, int d) {
    while (x <= n) {
        bit[x] += d;
        x += lowbit(x);
    }
}

int sum(int x) {
    int t = 0;
    while (x > 0) {
        t += bit[x];
        x -= lowbit(x);
    }
    return t;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        add(i, a[i] - a[i - 1]);
    }
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, y, k;
            cin >> x >> y >> k;
            add(x, k);
            add(y + 1, -k);
        } else {
            int x; cin >> x;
            cout << sum(x) << '\n';
        }
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