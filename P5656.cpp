#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int ext_gcd(int a, int b, int& x, int& y)
{
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    int x1, y1;
    int gcd = ext_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

void solve()
{
    int a, b, t;
    cin >> a >> b >> t;

    int x1, y1;
    int gcd = ext_gcd(a, b, x1, y1);
    // cerr << x1 << " " << y1 << '\n';
    int x = x1 * (t / gcd), y = y1 * (t / gcd);
    int k = a / gcd, q = b / gcd;
    int m_max, m_min;
    cerr << m_max << " " << m_min << '\n';
    cout << m_max - m_min + 1 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}