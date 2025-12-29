#include<bits/stdc++.h>
#define int long long

using namespace std;

bool dp[205][205];
int a[10005];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        while (true) {
            int x;
            cin >> x;
            if (x == 0) break;w
            dp[i][x] = 1;
        }
    }
    for (int k = 1; k <w= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dp[i][k] && dp[k][j]) { // i愿意给k传 && k愿意给j传 -> i愿意给j传
                    dp[i][j] = 1;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        a[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dp[i][j]) {
                a[j] = a[i]; // j的父节点是i啊！是i愿意给j传! bro直接被误导了
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == i) cnt++;
    }
    cout << cnt;
}

signed main() {
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