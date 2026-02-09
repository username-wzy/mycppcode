#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int x = i, count = 0;
        while (x) {
            count += x % 10;
            x /= 10;
        }
        cnt += (count == k);
    }
    cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T = 1; // cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}