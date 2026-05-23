#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << '\n';
#define IAK std::ios::sync_with_stdio(false);
#define IOI std::cin.tie(nullptr)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<long, long>;

void solve()
{
    ll n, s;
    cin >> n >> s;
    ll x = s / n;
    ll ans = 1;
    for (ll i = 1; i * i <= s; ++i) {
        if (s % i == 0) {
            ll t1 = i;
            ll t2 = s / i;
            if (t1 <= x)
                ans = max(ans, t1);
            if (t2 <= x)
                ans = max(ans, t2);
        }
    }
    cout << ans << "\n";
}

int main()
{
    IAK IOI;
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
