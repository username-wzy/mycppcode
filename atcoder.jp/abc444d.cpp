#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 2e5 + 5;

int d[N], a[N];

void solve() {
    int n;
    cin >> n;
    int maxn = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        maxn = max(maxn, a[i]);
    }
    for (int i = 1; i <= n; i++) {
        d[maxn - a[i] + 1]++, d[maxn + 1]--;
    }
    for (int i = 1; i <= maxn; i++) {
        d[i] += d[i - 1];
    }
    for (int i = maxn; i >= 1; i--) {
        if (d[i] > 9) {
            d[i - 1] += d[i] / 10;
            d[i] %= 10;
        }
    }
    if (d[0] > 0) cout << d[0];
    for (int i = 1; i <= maxn; i++) {
        cout << d[i];
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T = 1; // cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}