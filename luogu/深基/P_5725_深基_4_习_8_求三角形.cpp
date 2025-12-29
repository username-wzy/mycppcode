#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, k = 1;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << setw(2) << setfill('0') << k++;
        }
        cout << '\n';
    }
    cout << '\n';
    k = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 2 * (n - i); j++) {
            cout << " ";
        }
        for (int j = 1; j <= i; j++) {
            if (k < 10) {
                cout << '0' << k++;
            } else cout << k++;
        }
        cout << '\n';
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