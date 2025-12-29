#include<bits/stdc++.h>
#define ll long long

using namespace std;

int dp[10][10][10][10], a[10][10];

void solve() {
    int n;
    cin >> n;
    while (true){
        int x, y, z;
        cin >> x >> y >> z;
        if (x && y && z) {
            a[x][y] = z;
        }
    }
    dp[1][1][1][1] = a[1][1];
    for (int i = 2; i <= n * 2 - 1;)
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