#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, cnt = 0;
    cin >> n;
    int last;
    cin >> last;
    for (int i = 2; i <= n; i++) {
        int x; cin >> x;
        bool a = last % 2, b = x % 2;
        if (a != b) {
            cnt++;
        }
        last = x;
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