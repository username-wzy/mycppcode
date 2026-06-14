#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << '\n';
#define IAK std::ios::sync_with_stdio(false);
#define IOI std::cin.tie(nullptr)

using namespace std;
using ll = long long;

/**
 * @File: 13
 * @Author: wzy
 * @Date: 2026-06-06 20:10
 */

void solve()
{
    int n, k, m;
    cin >> n >> k >> m;

    vector<vector<ll>> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        int c;
        ll v;
        cin >> c >> v;
        arr[c].push_back(v);
    }

    vector<ll> db; // 存代表每个颜色最大的
    vector<ll> dr; // 存随便地
    db.reserve(n + 1);
    dr.reserve(n + 1);
    for (int i = 1; i <= n; i++) {
        if (!arr[i].empty()) {
            ranges::sort(arr[i], greater<>());
            db.push_back(arr[i][0]);
            for (int j = 1; j < arr[i].size(); j++)
                dr.push_back(arr[i][j]);
        }
    }
    ranges::sort(db, greater<>());

    ll ans = 0;
    for (int i = 0; i < m; i++)
        ans += db[i];
    for (int i = m; i < db.size(); i++)
        dr.push_back(db[i]);

    ranges::sort(dr, greater<>());
    for (int i = 0; i < k - m; i++)
        ans += dr[i];

    cout << ans;
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