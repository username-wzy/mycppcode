#include<bits/stdc++.h>
#define ll long long

using namespace std;

constexpr int N = 1e5 + 5;

int a[N], bit[N];
int n;
set<int> st;
unordered_map<int, int> mp, tong;

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

int f(int x) {
    int l = 1, r = n, ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        int cnt = sum(mid);
        if (cnt < (x + 1) / 2) {
            l = mid + 1;
        } else {
            r = mid - 1;
            ans = tong[mid];
        }
    }
    return ans;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        st.insert(a[i]);
    }
    int k = 1;
    for (auto p : st) {
        tong[k] = p;
        mp[p] = k++;
    }
    for (int i = 1; i <= n; i++) {
        a[i] = mp[a[i]];
        add(a[i]);
        if (i % 2) {
            cout << f(i) << '\n';
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