#include<bits/stdc++.h>
#define ll long long

using namespace std;

int a[15][15];

void solve() {
    int n;
    int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0}, now = 0;
    memset(a, -1, sizeof(a));
    
    cin >> n;
    int x = 1, y = 1, k = 1;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) a[i][j] = 0;
    while (k <= n * n) {
        a[x][y] = k++;
        cerr << x << " " << y << "\n";
        int xx = x + dx[now], yy = y + dy[now];
        if (a[xx][yy] != 0) {
            now = (now + 1) % 4;
        }
        x += dx[now];
        y += dy[now];
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cout << setw
        (3) << a[i][j];
        cout << '\n';
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