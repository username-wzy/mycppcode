#include<bits/stdc++.h>
#define ll long long

using namespace std;

int n, m, cnt = 0, dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
bool a[7][7];

void dfs(int x, int y) {
    bool flag1 = false, flag2 = false;
    for (int i = 1; i <= n; i++) {
        if (a[i][1]) flag1 = true;
        else flag2 = true;
    }
    for (int i = 1; i <= n; i++) {
        if (a[i][m]) flag1 = true;
        else flag2 = true;
    }
    for (int i = 1; i <= m; i++) {
        if (a[1][i]) flag1 = true;
        else flag2 = true;
    }
    for (int i = 1; i <= m; i++) {
        if (a[n][i]) flag1 = true;
        else flag2 = true;
    }
    if (flag1 && flag2) {
        cnt++;
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && !a[xx][yy]) {
                a[xx][yy] = true;
                dfs(xx, yy);
                a[xx][yy] = false;
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            memset(a, 0, sizeof(a));
            a[i][j] = true;
            dfs(i, j);
        }
    }
    cout << cnt << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // freopen("xxx.in", "r", stdin);
    // freopen("xxx.out", "w", stdout);

    int T = 1; // cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}