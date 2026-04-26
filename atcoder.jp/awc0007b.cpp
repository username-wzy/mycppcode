#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<vector<string>> a(n);
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        a[i].resize(m);
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int cnt = 0;
            for (int p = 0; p < static_cast<int>(a[i].size()); p++) {
                for (int q = 0; q < static_cast<int>(a[j].size()); q++) {
                    if (a[i][p] == a[j][q])
                        cnt++;
                }
            }
            if (cnt >= k)
                ans++;
        }
    }

    cout << ans;

    return 0;
}
