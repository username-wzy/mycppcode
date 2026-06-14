#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << '\n';
#define IAK std::ios::sync_with_stdio(false);
#define IOI std::cin.tie(nullptr)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<long, long>;

ll c[55][55], vec[55];
map<ll, int, greater<>> mp;

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    for (int i = 0; i <= n; i++)
        c[i][0] = 1;
    //  c[i][i] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
    for (int i = 1; i <= n; i++) {
        cin >> vec[i];
        mp[vec[i]]++;
    }
    sort(vec + 1, vec + 1 + n, greater<ll>());
    ll ans = 0;
    for (int i = a; i <= b; i++) {
        if (i == a || vec[i] == vec[1]) {
            const ll x = mp[vec[i]];
            ll y = i;
            for (auto p : mp) {
                if (p.first > vec[i])
                    y -= p.second;
                else
                    break;
            }
            ans += c[x][y];
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