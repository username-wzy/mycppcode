#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 2505;

char mp[N][N];
int h[N][N], w[N][N];
bool g[N][N];
bool vis[N];
int match[N];
int cnt_h, cnt_w;

bool dfs(int u)
{
    for (int v = 1; v <= cnt_w; v++) {
        if (!vis[v] && g[u][v]) {
            vis[v] = true;
            if (!match[v] || dfs(match[v])) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mp[i][j] != '#') {
                cnt_h++; // 遇到非硬石头，开启一个新块
                while (j <= m && mp[i][j] != '#') {
                    h[i][j] = cnt_h; // 该块覆盖的所有格子（含 * 和 x）
                    j++;
                }
            }
        }
    }

    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            if (mp[i][j] != '#') {
                cnt_w++; // 遇到非硬石头，开启一个新块
                while (i <= n && mp[i][j] != '#') {
                    w[i][j] = cnt_w; // 该块覆盖的所有格子（含 * 和 x）
                    i++;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (mp[i][j] == '*')
                g[h[i][j]][w[i][j]] = true;

    int ans = 0;
    for (int i = 1; i <= cnt_h; i++) {
        memset(vis, false, sizeof(vis));
        if (dfs(i))
            ans++;
    }

    cout << ans << '\n';
    return 0;
}