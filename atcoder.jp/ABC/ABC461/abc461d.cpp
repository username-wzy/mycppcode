#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << '\n';
#define IAK std::ios::sync_with_stdio(false);
#define IOI std::cin.tie(nullptr)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

/**
 * @File: 1
 * @Author: wzy
 * @Date: 2026-06-06 20:45
 */
// 3122

bool arr[505][505];

void solve()
{
    int h, w, k;
    cin >> h >> w >> k;
    vector s(h + 1, vector<int>(w + 1, 0));
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            char ch;
            cin >> ch;
            s[i][j] = s[i - 1][j] + (ch - '0');
        }
    }

    ll ans = 0;
    for (int i = 1; i <= h; i++) {
        for (int j = i; j <= h; j++) {
            map<ll, int> notebook;
            notebook[0] = 1;
            ll cs = 0;
            for (int c = 1; c <= w; c++) {
                // 算出当前列在 i 到 j 之间有多少个 1
                const int one_num = s[j][c] - s[i - 1][c];
                cs += one_num;

                // 查记事本
                const ll target = cs - k;
                if (notebook.count(target)) {
                    ans += notebook[target];
                }
                // 记入记事本
                notebook[cs]++;
            }
        }
    }

    cout << ans << '\n';
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
