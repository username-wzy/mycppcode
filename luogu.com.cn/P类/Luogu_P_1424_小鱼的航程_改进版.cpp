#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    int x, n;
    ll sum = 0;
    cin >> x >> n;
    while (n--) {
        if (!(x == 6 || x == 7)) {
            sum += 250;
        }
        x++;
        if (x == 8)
            x = 1;
    }
    cout << sum;
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