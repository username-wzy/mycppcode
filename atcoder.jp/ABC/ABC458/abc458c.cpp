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
    string s;
    cin >> s;
    const int n = s.size();
    s = " " + s;
    ll cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'C') {
            cnt += min(i, n - i + 1);
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