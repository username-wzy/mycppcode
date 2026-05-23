#include <iostream>

using namespace std;

typedef long long ll;
const int MOD = 9901;

// 快速幂计算 (a^b) % p
ll qpow(ll a, ll b)
{
    ll res = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

ll C(ll m, ll n)
{
    ll fenzi = 1, fenmu = 1;
    for (int i = 0; i < n; ++i) {
        fenzi = fenzi * (m - i) % MOD;
        fenmu = fenmu * (i + 1) % MOD;
    }
    return fenzi * qpow(fenmu, MOD - 2) % MOD;
}

ll lucas(ll m, ll n)
{
    if (n == 0)
        return 1;
    return (lucas(m / MOD, n / MOD) * C(m % MOD, n % MOD)) % MOD;
}

int main()
{
    ll m, n;
    cin >> m >> n;
    if (n > m) {
        cout << 0;
    } else {
        cout << lucas(m, n);
    }
    return 0;
}