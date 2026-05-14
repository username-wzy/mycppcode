#include <bits/stdc++.h>
#define IAK std::ios::sync_with_stdio(false);
#define IOI std::cin.tie(nullptr)
using namespace std;

void solve()
{
    int n;
    cin >> n;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        while (x % 2 == 0) {
            ans++;
            x /= 2;
        }
    }
    cout << ans << "\n";
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