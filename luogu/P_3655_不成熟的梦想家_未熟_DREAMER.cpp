#include<bits/stdc++.h>
#define int long long

using namespace std;

constexpr int N = 2e5 + 5;

int n, bit[N], S, T;

int lowbit(int x) {return x & -x;}

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

int jisuan(int x){
    return x > 0 ? -S * x : -T * x;
}

void solve() {
    int q, last = 0, f;
    int ans = 0;
    cin >> n >> q >> S >> T;
    cin >> f;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        add(i, x - last);
        ans += jisuan(x - last);
        last = x;
    }
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        ans -= jisuan(sum(l) - sum(l - 1));
        add(l, k);
        ans += jisuan(sum(l) - sum(l - 1));
        if (r != n) {
            ans -= jisuan(sum(r + 1) - sum(r));
            add(r + 1, -k);
            ans += jisuan(sum(r + 1) - sum(r));
        }

        cout << ans << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int T = 1;
    while(T--) {
        solve();
    }
    
    return 0;
}