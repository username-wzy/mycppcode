#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int id = 0, mx = 0;
    for (int i = 1; i <= 7; i++) {
        int a, b;
        cin >> a >> b;
        if (a + b > 8) {
            if (a + b > mx) {
                mx = a + b;
                id = i;
            }
        }
    }
    cout << id;
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
