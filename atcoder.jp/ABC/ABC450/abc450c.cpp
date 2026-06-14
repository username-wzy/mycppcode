#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1e3 + 5;

char mp[N][N];
bool vis[N][N];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int n, m;

void dfs(int i, int j)
{
    for (int k = 0; k < 4; k++) {
        int xx = i + dx[k];
        int yy = j + dy[k];
        if (xx > 1 && xx < n && yy > 1 && yy < m && mp[xx][yy] == '.' && !vis[xx][yy]) {
            vis[xx][yy] = true;
            dfs(xx, yy);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
        }
    }
    int cnt = 0;
    // 枚举四周
    for (int j = 1; j <= m; j++) {
        if (mp[1][j] == '.' && !vis[1][j]) {
            vis[1][j] = true;
            dfs(1, j);
        }
        if (mp[n][j] == '.' && !vis[n][j]) {
            vis[n][j] = true;
            dfs(n, j);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (mp[i][1] == '.' && !vis[i][1]) {
            vis[i][1] = true;
            dfs(i, 1);
        }
        if (mp[i][m] == '.' && !vis[i][m]) {
            vis[i][m] = true;
            dfs(i, m);
        }
    }
    for (int i = 2; i < n; i++) {
        for (int j = 2; j < m; j++) {
            if (mp[i][j] == '.' && !vis[i][j]) {
                vis[i][j] = true;
                dfs(i, j);
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}