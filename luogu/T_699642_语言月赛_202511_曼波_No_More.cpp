#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll n, m, r, c, ans = 0;
    ll x1, y1, x2, y2;
    cin >> n >> m >> r >> c;
    cin >> x1 >> y1 >> x2 >> y2;
    
    ll sx = (x1 + r) / r;
    if (x1 % r == 0) sx = x1 / r;
    
    ll sy = (y1 + c) / c;
    if (y1 % c == 0) sy = y1 / c;
    
    ll ex = x2 / r;
    if (x2 % r == r - 1) ex = x2 / r;
    else ex = (x2 + 1) / r - 1;
    
    ll ey = y2 / c;
    if (y2 % c == c - 1) ey = y2 / c;
    else ey = (y2 + 1) / c - 1;
    
    if (ex >= sx && ey >= sy) {
        ans = (ex - sx + 1) * (ey - sy + 1);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int T = 1;
    while(T--) {
        solve();
    }
    
    return 0;
}