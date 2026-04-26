#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

char mp[1005][1005];
bool vis[1005][1005];
int n, m;

void solve()
{
    int k;
    cin >> n >> m >> k;
    int x, y, d;
    cin >> x >> y >> d;

    memset(mp, 0, sizeof mp);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
        }
    }
    memset(vis, 0, sizeof vis);
    const int dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 };
    int cnt = 1;
    vis[x][y] = true;
    while (k--) {
        // cerr << x << " " << y << " " << d << '\n';
        int nx = x + dx[d], ny = y + dy[d];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && mp[nx][ny] == '.') {
            x = nx, y = ny;
            if (!vis[x][y]) {
                vis[x][y] = true;
                cnt++;
            }
        } else {
            d = (d + 1) % 4;
        }
    }

    cout << cnt << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    // T = 1;
    while (T--)
        solve();

    return 0;
}