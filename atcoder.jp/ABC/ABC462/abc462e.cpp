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
    ll a, b, x, y;
    cin >> a >> b >> x >> y;
    x = abs(x);
    y = abs(y);

    ll ans = min(x, y) * 2 * min(a, b);
    if (a < b)
        b = min(b, 3 * a);
    else
        a = min(a, 3 * b);
    if (x < y) {
        // 向上走
        const ll step = y - x;
        ans += (step / 2) * (a + b);
        if (step & 1)
            ans += b;
    } else if (x > y) {
        // 向右走
        const ll step = x - y;
        ans += (step / 2) * (a + b);
        if (step & 1)
            ans += a;
    }
    cout << ans << endl;
}

int main()
{
    IAK IOI;
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}