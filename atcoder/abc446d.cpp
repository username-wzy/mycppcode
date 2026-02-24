#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    map<int, int> dp;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        dp[x] = dp[x - 1] + 1;
        ans = max(ans, dp[x]);
    }

    cout << ans << "\n";

    return 0;
}