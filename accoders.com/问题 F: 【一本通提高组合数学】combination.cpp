#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

constexpr int p = 5000011;

ll qpow(ll a, ll b, ll p)
{
    ll res = 1;
    while (b) {
        if (b & 1)
            res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

ll C(ll n, ll m, ll p)
{
    if (m > n)
        return 0;
    if (n - m < m)
        m = n - m;
    ll up = 1;
    ll down = 1;
    for (int i = 1; i <= m; i++) {
        up = up * (n - i + 1) % p;
        down = down * i % p;
    }
    return up * qpow(down, p - 2, p) % p;
}

ll lucas(ll n, ll m, ll p)
{
    if (m == 0)
        return 1;
    return lucas(n / p, m / p, p) * C(n % p, m % p, p) % p;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // int T;
    // cin >> T;
    // while (T--) {
        ll n, m;
        cin >> n >> m;
        cout << lucas(n, m, p) << '\n';
    // }

    return 0;
}