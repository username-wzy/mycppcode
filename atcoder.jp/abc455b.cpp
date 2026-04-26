#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

char a[15][15];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w;
    cin >> h >> w;

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> a[i][j];
        }
    }

    int ans = 0;

    for (int h1 = 1; h1 <= h; h1++) {
        for (int h2 = h1; h2 <= h; h2++) {
            for (int w1 = 1; w1 <= w; w1++) {
                for (int w2 = w1; w2 <= w; w2++) {
                    bool flag = true;
                    for (int i = h1; i <= h2; i++) {
                        for (int j = w1; j <= w2; j++) {
                            if (a[i][j] != a[h1 + h2 - i][w1 + w2 - j])
                                flag = false;
                        }
                    }
                    ans += flag;
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}