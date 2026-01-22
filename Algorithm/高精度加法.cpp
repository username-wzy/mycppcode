#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    string a, b, c;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int jw = 0;
    for (int i = 0; i < max(a.size(), b.size()); i++) {
        int x = (i >= a.size()) ? 0 : a[i] - '0', y = (i >= b.size()) ? 0 : b[i] - '0';
        int k = (x + y + jw) % 10;
        c.push_back(k + '0');
        jw = (x + y + jw) / 10;
    }
    if (jw)
        c.push_back(jw + '0');
    reverse(c.begin(), c.end());
    cout << c;
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