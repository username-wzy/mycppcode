#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << '\n';

using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;

    // block[i] 记录位置 i 放下的方块绝对总数
    vector<int> block(n + 1, 0);
    // grt[i] 记录绝对方块数至少为 i 的位置数
    vector<int> grt(q + 5, 0);

    grt[0] = n;
    int min_cnt = 0; // 记录全局被消除的层数（即所有列的最小高度）
    const int tq = q;

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            cin >> x;

            block[x]++;
            grt[block[x]]++; // 绝对高度达到 block[x] 的列数 +1

            // 如果所有列的绝对高度都达到了 block[x]，说明底层铺满了，整体消除层数 +1
            if (grt[block[x]] == n) {
                min_cnt++;
            }
        } else {
            int y;
            cin >> y;

            if (y + min_cnt > tq)
                cout << 0 << '\n';
            else
                cout << grt[y + min_cnt] << '\n';
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--)
        solve();

    return 0;
}