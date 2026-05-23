#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << '\n';
#define IAK std::ios::sync_with_stdio(false);
#define IOI std::cin.tie(nullptr)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<long, long>;

void solve()
{
    int h, w;
    cin >> h >> w;
    int dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 };
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            int cnt = 0;
            for (int k = 0; k < 4; k++) {
                int nx = dx[k] + i, ny = dy[k] + j;
                if (nx >= 1 && ny >= 1 && nx <= h && ny <= w)
                    cnt++;
            }
            cout << cnt << " ";
        }
        cout << '\n';
    }
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