#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    double h, r;
    cin >> h >> r;
    double v = r * r * 3.14 * h;
    v /= 1000;
    cout << ceil(20 / v);
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