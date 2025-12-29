#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, a[105][105];
    cin >> n;
    int x = 1, y = (n + 1) / 2;
    for (int i = 1; i <= n * n; i++) {
        a[x][y] = i;
        x--, y++;
        if ((x == 0 && y == n + 1) || a[x][y] != 0) {
            x += 2;
            y--;
        } else if (x == 0) {
            x = n;
        } else if (y == n + 1) {
            y = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
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