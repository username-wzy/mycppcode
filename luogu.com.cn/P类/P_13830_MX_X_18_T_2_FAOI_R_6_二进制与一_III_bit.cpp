#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    double n;
    cin >> n;
    cout << int(n * (2 / 3.0)) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // freopen("xxx.in", "r", stdin);
    // freopen("xxx.out", "w", stdout);

    int T = 1; cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}