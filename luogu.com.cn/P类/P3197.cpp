#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MOD = 100003;

ll fast_pow(unsigned ll base, ll power, ll mod)
{
    ll result = 1;
    while (power > 0) {
        if (power & 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        power >>= 1;
    }
    return result;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    unsigned ll n, m;
    cin >> m >> n;
    const int all = fast_pow(m, n, MOD);
    const int other = m * fast_pow(m - 1, n - 1, MOD) % MOD;
    cout << ((all - other) + MOD) % MOD;
    return 0;
}