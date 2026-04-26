#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int dist[5005][5005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c;
    cin >> a >> b >> c;

    memset(dist, -1, sizeof(dist));
    queue<pair<int, int>> q;

    dist[0][0] = 0;
    q.push({ 0, 0 });

    int min_you = c;
    int min_step = 0;

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        int x = curr.first;
        int y = curr.second;
        int z = c - x - y;

        if (x > 0 && x < min_you) {
            min_you = x;
            min_step = dist[x][y];
        }
        if (y > 0 && y < min_you) {
            min_you = y;
            min_step = dist[x][y];
        }
        if (z > 0 && z < min_you) {
            min_you = z;
            min_step = dist[x][y];
        }

        if (min_you == 1) {
            break;
        }

        pair<int, int> nxt_dis[6];
        // c -> a
        int move = min(z, a - x);
        nxt_dis[0] = { x + move, y };
        // c -> b
        move = min(z, b - y);
        nxt_dis[1] = { x, y + move };
        // a -> b
        move = min(x, b - y);
        nxt_dis[2] = { x - move, y + move };
        // a -> c
        move = min(x, c - z);
        nxt_dis[3] = { x - move, y };
        // b -> a
        move = min(y, a - x);
        nxt_dis[4] = { x + move, y - move };
        // b -> c
        move = min(y, c - z);
        nxt_dis[5] = { x, y - move };

        for (auto p : nxt_dis) {
            int nx = p.first;
            int ny = p.second;
            int nz = c - nx - ny;

            if (dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({ nx, ny });
            }
        }
    }

    cout << min_you << '\n'
         << min_step << '\n';

    return 0;
}