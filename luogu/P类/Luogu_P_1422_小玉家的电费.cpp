#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    double x, y = 0;
    cin >> x;
    cout << fixed << setprecision(1);
    if (x >= 401) {
        y += (x - 400) * 0.5663;
        x = 400;
    }
    if (x >= 151) {
        y += (x - 150) * 0.4663;
        x = 150;
    }
    y += x * 0.4463;
    cout << y;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // freopen("xxx.in", "r", stdin);
    // freopen("xxx.out", "w", stdout);

    int T = 1; // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}