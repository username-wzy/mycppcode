#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    double t;
    int n;
    cin >> t >> n;
    printf("%.3lf\n%d", t / n, n * 2);
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