#include <bits/stdc++.h>
#define IAK std::ios::sync_with_stdio(false);
#define IOI std::cin.tie(nullptr)
using namespace std;
typedef long long ll;
void solve()
{
    long long x;
    cin >> x;
    ll l = 0, r = 1000000;
    ll ans = 0;
    while (l <= r) {
        ll mid = (l + r) / 2;
        cerr << mid << '\n';
        if (mid * mid * mid <= x && (mid + 1) * (mid + 1) * (mid + 1) > x) {
            r = mid - 1;
            ans = mid;
        } else if (mid * mid * mid > x) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << " " << ans + 1;
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