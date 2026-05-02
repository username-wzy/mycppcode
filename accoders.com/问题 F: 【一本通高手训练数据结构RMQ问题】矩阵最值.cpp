#include <iostream>

using namespace std;

int n, m;
int st[251][251][9][9];
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
            scanf("%d", &st[i][j][0][0]);
        }
    }
    // pre
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for () {
            }
        }
        ,
    }
    int x1, y1, x2, y2;
    while (q--) {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        const int k1 = log_2[x2 - x1 + 1];
        const int k2 = log_2[y2 - y1 + 1];

        // 四个矩形块的左上角坐标分别是：
        // 1. (x1, y1)
        // 2. (x1, y2 - (1 << k2) + 1)
        // 3. (x2 - (1 << k1) + 1, y1)
        // 4. (x2 - (1 << k1) + 1, y2 - (1 << k2) + 1)

        int m1 = st[x1][y1][k1][k2];
        int m2 = st[x1][y2 - (1 << k2) + 1][k1][k2];
        int m3 = st[x2 - (1 << k1) + 1][y1][k1][k2];
        int m4 = st[x2 - (1 << k1) + 1][y2 - (1 << k2) + 1][k1][k2];

        int ans = max(max(m1, max(m2, m3)), m4);
        printf("%d\n", ans);
    }

    return 0;
}
