#include <bits/stdc++.h>
#define IAK std::ios::sync_with_stdio(false);
#define IOI std::cin.tie(nullptr)
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    const ll mod = 1e9 + 7;
    ll ans = 0;
    for (int bit = 0; bit <= 60; bit++) {
        ll cnt1 = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] >> bit & 1)
                cnt1++;
        }
        ll cnt0 = n - cnt1;
        ll s = (1LL << bit) % mod;
        ans += s % mod * cnt1 % mod * cnt0 % mod;
        ans %= mod;
    }
    cout << ans;
}

int main()
{
    IAK IOI;
    int T = 1;
    while (T--)
        solve();
    return 0;
}
