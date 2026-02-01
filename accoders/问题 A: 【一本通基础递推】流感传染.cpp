#include <iostream>

char a[105][105], b[105][105];
int n;

bool inside(int x, int y)
{
    return x >= 1 && x <= n && y >= 1 && y <= n;
}

int main()
{
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            std::cin >> a[i][j];
            b[i][j] = a[i][j];
        }
    }
    int q;
    std::cin >> q;
    q--;
    const int dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 };
    while (q--) {
        for (int x = 1; x <= n; x++) {
            for (int y = 1; y <= n; y++) {
                if (a[x][y] != '@')
                    continue;
                for (int k = 0; k < 4; k++) {
                    int xx = x + dx[k], yy = y + dy[k];
                    if (inside(xx, yy) && a[xx][yy] == '.') {
                        b[xx][yy] = '@';
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                a[i][j] = b[i][j];
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cnt += (a[i][j] == '@');
    std::cout << cnt << '\n';
    return 0;
}