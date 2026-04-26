#include<bits/stdc++.h>
#define ll long long

using namespace std;

bool a[1005][1005];
int n;

void solve() {
    int m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; i++) {
        cnt1 += a[m][i];
        cnt2 += a[i][m];
    }
    cout << cnt1 << " " << cnt2 << " " << cnt1 + cnt2 << "\n";
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