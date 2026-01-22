#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve()
{
    string a;
    int b;
    cin >> a >> b;
    int r = 0;
    string ans;
    for (auto ch : a) {
        r = r * 10 + (ch - '0');
        ans.push_back(r / b + '0');
        r %= b;
    }
    int l = 0;
    while (l < ans.size() - 1 && ans[l] == '0')
        l++;
    for (size_t i = l; i < ans.size(); i++) {
        cout << ans[i];
    }
}

signed main()
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