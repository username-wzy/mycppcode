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
    int n, d, a;
    cin >> n >> d >> a;
    priority_queue<pll> q;
    for (int i = 0; i < n; i++) {
        ll p, v;
        cin >> p >> v;
        q.emplace(-p, v);
    }
    ll curr = 0, cnt = 0;
    while (!q.empty()) {
        auto p = q.top();
        q.pop();
        ll k = -p.first, m = p.second;
        if (m >= 0) {
            if (m > curr) {
                ll t;
                t = ceil((m - curr) * 1.0 / a);
                cnt += t;
                curr += t * a;
                q.emplace(-(k + 2 * d), -t);
            }
        } else {
            curr += a * m;
        }
    }
    cout << cnt;
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
