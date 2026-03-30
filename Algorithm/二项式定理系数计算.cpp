#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll mod = 10000 + 7;

ll qpow(ll a, ll b) {
    a %= mod;
    ll res = 1;
    while (b) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll C(ll n, ll k) {
    if (n - k < k)  
        k = n - k;
    n = n % mod;
    k = k % mod;

    vector<vector<ll>> table(n + 1, vector<ll>(n + 1, 0));
    table[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        table[i][0] = 1;
        table[i][i] = 1;
        for (int j = 1; j < i; j++) {
            table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % mod;
        }
    }
    return table[n][k];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a, b, k, n, m;
    cin >> a >> b >> k >> n >> m;
    // C_k^n \cdot a^n \cdot b^m \cdot x^n \cdot y^m

    cout << C(k, n) * qpow(a, n) % mod * qpow(b, m) % mod << '\n';
    return 0;
}