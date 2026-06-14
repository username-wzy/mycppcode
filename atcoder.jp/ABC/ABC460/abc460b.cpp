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
    ll x1, y1, x2, y2, r1, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    ll dis = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2); // dis ^ 2

    // (r1 - r2) ^ 2 <= dis ^ 2 <= (r1 + r2) ^ 2

    if ((r1 - r2) * (r1 - r2) <= dis && dis <= (r1 + r2) * (r1 + r2)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
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