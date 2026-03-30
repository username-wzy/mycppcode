#include<bits/stdc++.h>

using namespace std;
typedef long long ll;


ll qpow(ll a, ll b, ll mod) {
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

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int q;
    cin >> q;
    while (q--) {
        int a, m;
        cin >> a >> m;
        if (a % m == 0)
            cout << "impossible\n";
        else
            cout << qpow(a, m - 2, m) << '\n';
    }

    return 0;
}