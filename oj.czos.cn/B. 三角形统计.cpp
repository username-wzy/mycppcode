#include <bits/stdc++.h>
#define IAK std::ios::sync_with_stdio(false);
#define IOI std::cin.tie(nullptr)
using namespace std;

typedef long ll;

unordered_map<int, ll> h, w;

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        ll x, y;
        cin >> x >> y;
        h[x]++;
        w[y]++;
    }
    ll ans = 0;
    for (ll i = -1e5; i <= 1e5; i++) {
        if (h[i] >= 2 && w[i] >= 2) {
            ans += max(0LL, (h[i] - 1LL) * (w[i] - 1LL));
        }
    }
    cout << ans;
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