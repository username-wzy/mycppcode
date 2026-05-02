#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= k;
    }
    sort(a.begin() + 1, a.end());
    a.erase(unique(a.begin() + 1, a.end()), a.end());
    if (a.size() == 1) {
        cout << 0 << '\n';
        return 0;
    }
    ll ans = a[n] - a[1];
    for (int i = 1; i < a.size(); i++) {
        ans = min(ans, (a[i] + k) - a[i + 1]);
    }
    cout << ans << '\n';
}
