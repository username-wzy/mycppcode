#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << '\n';
#define IAK std::ios::sync_with_stdio(false);
#define ATCODER std::cin.tie(nullptr)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<long, long>;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    map<int, int> ab, ac, bc;
    map<pii, int> abc;
    int pab, pac, pbc; // prefix sum of a - b. a - c, b - c
    pab = pac = pbc = 0;
    ab[0] = ac[0] = bc[0] = abc[{ 0, 0 }] = 1;
    ll ans = n * 1LL * (n + 1) / 2;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') {
            pab++;
            pac++;
        } else if (s[i] == 'B') {
            pab--;
            pbc++;
        } else {
            pac--;
            pbc--;
        }
        ans -= ab[pab] + ac[pac] + bc[pbc] - 2 * abc[{ pab, pac }];
        ab[pab]++, ac[pac]++, bc[pbc]++, abc[{ pab, pac }]++;
    }
    cout << ans;
}

int main()
{
    IAK ATCODER;
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
