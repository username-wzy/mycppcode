#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, p;
    cin >> n >> p;

    vector<ll> inv(n + 1);
    inv[1] = 1;

    cout << 1 << "\n";
    for (int i = 2; i <= n; i++) {
        inv[i] = (p - p / i) * inv[p % i] % p;
        cout << inv[i] << "\n";
    }
    return 0;
}