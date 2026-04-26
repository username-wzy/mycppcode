#include<bits/stdc++.h>
#define ll long long

using namespace std;

constexpr int N = 30005;

int a[N], n, bit[N], l[N], r[N], b[N]; // l 数组代表当前数左边比他小的数的个数 r 数组代表当前这个数比他大的数的个数

int lowbit(int x) {return x & -x;}

void add(int x) {
    while (x <= n) {
        bit[x]++;
        x += lowbit(x);
    }
}

int sum(int x) {
    ll t = 0;
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
    int k = 0;
    for (auto p : st) {
        mp[p] = ++k;
    }
    for (int i = 1; i <= n; i++) {
        b[i] = mp[a[i]];
    }
    for (int i = 1; i <= n; i++) {
        cerr << a[i] << " ";
    }
    cerr << '\n';
    for (int i = 1; i <= n; i++) {
        add(b[i]);
        l[i] = sum(b[i] - 1); // 比它小的数的个数
    }
    memset(bit, 0, sizeof(bit)); // 清空树状数组
    for (int i = n; i >= 1; i--) {
        add(b[i]);
        r[i] = n - i + 1 - sum(b[i]);// 比它大的数 就是用n - i + 1 比它小的数的个数
    }
    for (int i = 1; i <= n; i++) {
        cerr << l[i] << " ";
    }
    cerr << '\n';
    for (int j = 1; j <= n; j++) {
        cerr << r[j] << " ";
    }
    ll ans = 0;
    for (int i = 2; i < n; i++) {
        ans += l[i] * r[i];
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