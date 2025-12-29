#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, k = 1, cnt = 0, c = 1;
    cin >> n;
    while (n--) {
        if (k == 0) {
            c++;
            k = c;
        }
        cnt += c;
        k--;
    }
    cout << cnt;
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