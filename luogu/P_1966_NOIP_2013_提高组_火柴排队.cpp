#include<bits/stdc++.h>
#define int long long

using namespace std;

constexpr int N = 5e5 + 5;

int bit[N], n, m, a[N];

int lowbit(int x) {
    return x & -x;
}

void add(int x) {
    while (x <= n) {
        bit[x]++;
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
    cin >> n;
    set<int> st;
    unordered_map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        st.insert(a[i]);
    }
    int k = 1, ans = 0;
    for (auto p : st) {
        mp[p] = k++;
    }
    for (int i = 1; i <= n; i++) {
        a[i] = mp[a[i]];
        add(a[i]);
        ans += i - sum(a[i]);
    }
    cout << ans;
}

signed  main() {
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