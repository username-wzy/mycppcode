#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int x1, x2, x3, y1, y2, y3;
    cin >> x1 >> x2 >> x3 >> y1 >> y2 >> y3;

    if (x1 * y1 + x2 * y2 + x3 * y3 == 0) {
        cout << "Orthogonal";
    } else cout << "Non-Orthogonal";
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