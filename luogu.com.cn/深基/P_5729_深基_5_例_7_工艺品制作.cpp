#include<bits/stdc++.h>
#define ll long long

using namespace std;

int v[40][40][40];

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int t;
    cin >> t;
    while (t--) {
        int x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        for (int i = x1; i <= x2; i++) {
            for (int j = y1; j <= y2; j++) {
                for (int k = z1; k <= z2; k++) {
                    v[i][j][k] = 1;
                }
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            for (int k = 1; k <= c; k++) {
                cnt += v[i][j][k];
            }
        }
    }
    cout << a * b * c - cnt;
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