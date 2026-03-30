#include <iostream>

using namespace std;

int n, m;
int st[251][251][9];
int log_2[251];

int main()
{
    int q;
    scanf("%d %d %d", &n, &m, &q);

    log_2[1] = 0;
    const int max_ = max(n, m);
    for (int i = 2; i <= max_; i++)
        log_2[i] = log_2[i >> 1] + 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &st[i][j][0]);
        }
        for (int p = 1; p <= 8; p++) {
            for (int j = 1; j + (1 << p) - 1 <= m; j++) {
                st[i][j][p] = max(st[i][j][p - 1], st[i][j + (1 << (p - 1))][p - 1]);
            }
        }
    }

    while (q--) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        const int k = log_2[y2 - y1 + 1];
        int ans = 0;
        for (int i = x1; i <= x2; i++)
            ans = max(ans, max(st[i][y1][k], st[i][y2 - (1 << k) + 1][k]));
        printf("%d\n", ans);
    }

    return 0;
}
