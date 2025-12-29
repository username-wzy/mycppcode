#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, x = 0, k = 0;
    cin >> n;
    for (int i = 1; i <= 100; i++) {
        for (int j = 200; j >= 1; j--) {
            if (i * 7 + j * 21 == n / 52) {
                x = i;
                k = j;
            }
        }
    }
    cout << x << '\n' << k;
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