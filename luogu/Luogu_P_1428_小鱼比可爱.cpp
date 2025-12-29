#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cout << 0 << " ";
    for (int i = 2; i <= n; i++) {
        int cnt = 0;
        for (int j = i - 1; j >= 1; j--) {
            if (a[j] < a[i]) {
                cnt++;
            }
        }
        cout << cnt << " ";
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