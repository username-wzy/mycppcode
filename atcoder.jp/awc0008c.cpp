#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for (int pos = 0; pos < n; pos++) {
        cin >> a[pos];
    }

    ll sum = 0;
    for (int pos = 0; pos < k; pos++) {
        sum += a[pos];
    }

    ll ans = 0;
    if (sum <= 0)
        ans++;

    for (int pos = k; pos < n; pos++) {
        sum += a[pos];
        sum -= a[pos - k];
        if (sum <= 0)
            ans++;
    }

    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T = 1;
    while (T--) {
        solve();
    }

    return 0;
}
