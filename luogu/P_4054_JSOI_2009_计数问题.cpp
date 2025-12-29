#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) (x&(-x))

using namespace std;

int a[305][305][105], n, m, color[305][305];

void add(int x, int y, int c, int d) {
    for (int i = x; i <= n; i += lowbit(i)) {
        for (int j = y; j <= m; j += lowbit(j)) {
            a[i][j][c] += d;
        }
    }
}

int sum(int x, int y, int c) {
    int cnt = 0;
    for (int i = x; i > 0; i -= lowbit(i)) {
        for (int j = y; j > 0; j-= lowbit(j)) {
            cnt += a[i][j][ c];
        }
    }
    return cnt;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        int c; cin >> c;
        color[i][j] = c;
        add(i, j, c, 1);
    }
    int q;
    cin >> q;
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int x, y, c;
            cin >> x >> y >> c;
            add(x, y, color[x][y], -1);
            color[x][y] = c;
            add(x, y, color[x][y], 1);
        } else {
            int x1, x2, y1, y2, c;
            cin >> x1 >> x2 >> y1 >> y2 >> c;
            cout << sum(x2, y2, c) - sum(x2, y1 - 1, c) - sum(x1 - 1, y2, c) + sum(x1 - 1, y1 - 1, c) << '\n';
        }
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