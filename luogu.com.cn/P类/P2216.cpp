#include <iostream>

using namespace std;

int st[1005][1005][15][15], st2[1005][1005][15][15];
int log_2[251];

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    log_2[1] = 0;
    const int max_ = max(n, m);
    for (int i = 2; i <= max_; i++)
        log_2[i] = log_2[i >> 1] + 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> st[i][j][0][0];
            st[i][j][0][0]
               
        }
    }
    


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= )
    }
        return 0;
}