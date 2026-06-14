#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << '\n';
#define IAK std::ios::sync_with_stdio(false);
#define IOI std::cin.tie(nullptr)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<long, long>;

constexpr int Max = 1e6;

void solve()
{
    int n, d;
    cin >> n >> d;
    vector<ll> a(Max + 5);
    for (int i = 1; i <= n; i++) {
        int s, t;
        cin >> s >> t;
        const int st = s, ed = t - d;
        if (st > ed)
            continue;
        a[st]++;
        a[ed + 1]--;
    }

    for (int i = 1; i <= Max; i++)
        a[i] += a[i - 1];

    ll ans = 0;
    for (int i = 0; i <= Max; i++)
        if (a[i] > 1)
            ans += a[i] * (a[i] - 1) / 2;

    cout << ans << endl;
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