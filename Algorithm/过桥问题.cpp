#include<bits/stdc++.h>
#define ll long long

using namespace std;

int n, a[1005];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int ans = 0;
    while (n >= 3) {
        ans += min(a[n] + a[1] + a[n - 1] + a[1], a[1] + a[2] + a[n] + a[1]); 
        // 方法1： 最大的人和最小的人一起过桥，最小的人回来，再让次大的人和最小的人一起过桥，最小的人回来， 
        // 方法2：最小的两个人一起过桥，最小的人回来，再让最大的人和最小的人一起过桥，最小的人回来
        //取两者的最小值
        n -= 2;
    }
    if (n == 3) {
        ans += a[1] + a[2] + a[3]; // 三个人一起过桥，最小的人回来两次
    } else if (n == 2) {
        ans += a[2]; // 两个人一起过桥
    } else if (n == 1) {
        ans += a[1]; // 一个人过桥
    }
    cout << ans;
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