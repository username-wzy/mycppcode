#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << -1;
    } else {
        cout << (n + 1) / 2;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int T = 1; // cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}