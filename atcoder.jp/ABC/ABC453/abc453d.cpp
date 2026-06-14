#include <bits/stdc++.h>

using namespace std;

struct State {
    int x, y, d;
};

struct Parent {
    int px, py, pd;
    char move;
} pre[1005][1005][4];

int n, m;
string g[1005];
bool vis[1005][1005][4];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
char dc[] = { 'U', 'R', 'D', 'L' };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    int sx, sy, ex, ey;
    for (int i = 0; i < n; ++i) {
        cin >> g[i];
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == 'S') {
                sx = i;
                sy = j;
            }
            if (g[i][j] == 'G') {
                ex = i;
                ey = j;
            }
        }
    }

    queue<State> q;
    // 起点 S 可以向四个方向出发
    for (int i = 0; i < 4; ++i) {
        int nx = sx + dx[i];
        int ny = sy + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && g[nx][ny] != '#') {
            if (!vis[nx][ny][i]) {
                vis[nx][ny][i] = true;
                pre[nx][ny][i] = { -1, -1, -1, dc[i] }; // 起点的父节点设为特殊值
                q.push({ nx, ny, i });
            }
        }
    }

    int end_d = -1;
    while (!q.empty()) {
        State curr = q.front();
        q.pop();

        if (curr.x == ex && curr.y == ey) {
            end_d = curr.d;
            break;
        }

        char x = g[curr.x][curr.y];
        for (int i = 0; i < 4; ++i) {
            // 规则判断
            if (x == 'o' && i != curr.d)
                continue; // 'o' 必须直行
            if (x == 'x' && i == curr.d)
                continue; // 'x' 不能直行

            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && g[nx][ny] != '#' && !vis[nx][ny][i]) {
                vis[nx][ny][i] = true;
                pre[nx][ny][i] = { curr.x, curr.y, curr.d, dc[i] };
                q.push({ nx, ny, i });
            }
        }
    }

    if (end_d != -1) {
        cout << "Yes" << '\n';
        string res = "";
        int cx = ex, cy = ey, cd = end_d;
        while (cx != -1) {
            res += pre[cx][cy][cd].move;
            Parent p = pre[cx][cy][cd];
            cx = p.px;
            cy = p.py;
            cd = p.pd;
        }
        reverse(res.begin(), res.end());
        cout << res << endl;
    } else {
        cout << "No" << '\n';
    }

    return 0;
}