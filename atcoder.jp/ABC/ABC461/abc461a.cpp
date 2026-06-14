#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << '\n';
#define IAK std::ios::sync_with_stdio(false);
#define IOI std::cin.tie(nullptr)

using namespace std;

/**
 * @File: 10
 * @Author: wzy
 * @Date: 2026-06-06 20:03
 */

void solve()
{
    int a, b;
    cin >> a >> b;
    cout << (a <= b ? "Yes" : "No") << '\n';
}

int main()
{
    IAK IOI;
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}