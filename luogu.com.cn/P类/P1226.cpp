#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll qpow(ll a, ll b, ll p) {
    ll ans = 1;
    ans %= p;
    while (b) {
        if (b & 1)
            ans = ans * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a, b, p;
    cin >> a >> b >> p;

    printf("%lld^%lld mod %lld=%lld", a, b, p, qpow(a, b, p));

    return 0;
}