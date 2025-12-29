#include<bits/stdc++.h>
#define ll long long

using namespace std;

constexpr int N = 3e5 + 10;

ll a[N], b[N], cnt = 0;

void merge_sort(ll l, ll r) {
    if (l < r) {
        ll mid = (l + r) / 2;
        merge_sort(l, mid);
        merge_sort(mid + 1, r);
        ll i = l, j = mid + 1, t = l;
        while (i <= mid && j <= r) {
            if (a[i] <= a[j]) cnt += r - j + 1, b[t++] = a[i++];
            else b[t++] = a[j++];
        }
        while (i <= mid) b[t++] = a[i++];
        while (j <= r) b[t++] = a[j++];
        for (i = l; i <= r; i++) a[i] = b[i];
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    merge_sort(1, n);
    cout << cnt;
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