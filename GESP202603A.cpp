#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> a(n + 1);
    vector<ll> b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    vector<ll> dp(n + 1);
    for (ll i = n; i >= 1; i--) {
        ll nxt = max(i + 1, i + b[i]);
        if (nxt <= n)
            dp[i] = max(dp[i + 1], a[i] + dp[nxt]);
        else
            dp[i] = max(dp[i + 1], a[i]);
    }
    cout << dp[1] << '\n';
    return 0;
}