#include<bits/stdc++.h>
#define ll long long

using namespace std;

int a[100005];

void solve() {
    int n, k, d;
    cin >> n >> k >> d;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    vector<int> ans;
    int count = 1;
    for (int i = 1; i < n; i++) {
        
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