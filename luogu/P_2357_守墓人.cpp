#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 5;

int n, f, c[N], a[N], cc[N];

int lowbit (int x) {
    return x & (x ^ (x - 1));
}

void add (int x, int d) {
    int t = x;
    while (x <= n) {
        c[x] += d;
        cc[x] += (t - 1) * d;
        x += lowbit(x);
    }
}
int sum(int x) {
    int t = 0, tt = x;
    while (x > 0) {
        t += c[x] * tt - cc[x];
        x -= lowbit(x);
    }
    return t;
}

void solve() {
    cin >> n >> f;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];    
        add(i, a[i] - a[i - 1]);
    }
    while (f--) {
        int op; cin >> op;
        // cerr << op;
        if (op == 1) {
            int l, r, k;
            cin >> l >> r >> k;
            add(l, k);
            add(r + 1, -k);
        } else if (op == 2) {
            int k; cin >> k;
            add(1, k); add(2, -k);
        } else if (op == 3) {
            int k; cin >> k;
            add(1, -k); add(2, k);
        } else if (op == 4) {
            int l, r;
            cin >> l >> r;
            cout << sum(r) - sum(l - 1)  << '\n';
        } else {    
            cout << c[1] << '\n';
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);


    solve();

    return 0;
}