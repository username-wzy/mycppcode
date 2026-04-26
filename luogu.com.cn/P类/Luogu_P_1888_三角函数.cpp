#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll a, b, c;
    cin >> a >> b >> c;
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    int l = __gcd(a, c);
    a /= l;
    c /= l;
    printf("%lld/%lld", a, c);
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // freopen("xxx.in", "r", stdin);
    // freopen("xxx.out", "w", stdout);

    int T = 1; // cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}