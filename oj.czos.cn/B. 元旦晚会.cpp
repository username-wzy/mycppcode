#include <bits/stdc++.h>
#define IAK std::ios::sync_with_stdio(false);
#define IOI std::cin.tie(nullptr)
using namespace std;
typedef long long ll;

ll a[int(1e5 + 5)];

void solve()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    ll minn = 1e9;
    for (int i = 1; i <= n - k + 1; i++) {
        minn = min(a[i + k - 1] - a[i], minn);
    }
    cout << minn;
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