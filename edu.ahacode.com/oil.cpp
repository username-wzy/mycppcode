#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int dist[5005][5005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c;
    cin >> a >> b >> c;

    int ans1 = __gcd(__gcd(a, b), c);

    memset(dist, -1, sizeof(dist));
    dist[0][0] = 0;
    queue<array<int, 3>> q;
    q.push({ 0, 0, c });

    cout << ans1 << '\n';

    if (c == ans1) { // 实际上 ans1 最小为 1，只需判断 c
        cout << 0 << '\n';
        return 0;
    }

    while (!q.empty()) {
        auto cur = q.front();
        int x = cur[0], y = cur[1], z = cur[2];
        q.pop();

        // c -> a
        int d = min(z, a - x);
        int nx = x + d, ny = y, nz = z - d;
        if (dist[nx][ny] == -1) {
            dist[nx][ny] = dist[x][y] + 1;
            q.push({ nx, ny, nz });
            if (nx == ans1 || ny == ans1 || nz == ans1) {
                cout << dist[nx][ny] << '\n';
                exit(0);
            }
        }

        // a -> b
        d = min(x, b - y);
        nx = x - d, ny = y + d, nz = z;
        if (dist[nx][ny] == -1) {
            dist[nx][ny] = dist[x][y] + 1;
            q.push({ nx, ny, nz });
            if (nx == ans1 || ny == ans1 || nz == ans1) {
                cout << dist[nx][ny] << '\n';
                exit(0);
            }
        }

        // c -> b
        d = min(z, b - y);
        nx = x, ny = y + d, nz = z - d;
        if (dist[nx][ny] == -1) {
            dist[nx][ny] = dist[x][y] + 1;
            q.push({ nx, ny, nz });
            if (nx == ans1 || ny == ans1 || nz == ans1) {
                cout << dist[nx][ny] << '\n';
                exit(0);
            }
        }

        // b -> a
        d = min(y, a - x);
        nx = x + d, ny = y - d, nz = z;
        if (dist[nx][ny] == -1) {
            dist[nx][ny] = dist[x][y] + 1;
            q.push({ nx, ny, nz });
            if (nx == ans1 || ny == ans1 || nz == ans1) {
                cout << dist[nx][ny] << '\n';
                exit(0);
            }
        }

        // b -> c
        d = min(y, c - z);
        nx = x, ny = y - d, nz = z + d;
        if (dist[nx][ny] == -1) {
            dist[nx][ny] = dist[x][y] + 1;
            q.push({ nx, ny, nz });
            if (nx == ans1 || ny == ans1 || nz == ans1) {
                cout << dist[nx][ny] << '\n';
                exit(0);
            }
        }

        // a -> c
        d = min(x, c - z);
        nx = x - d, ny = y, nz = z + d;
        if (dist[nx][ny] == -1) {
            dist[nx][ny] = dist[x][y] + 1;
            q.push({ nx, ny, nz });
            if (nx == ans1 || ny == ans1 || nz == ans1) {
                cout << dist[nx][ny] << '\n';
                exit(0);
            }
        }
    }
    return 0;
}