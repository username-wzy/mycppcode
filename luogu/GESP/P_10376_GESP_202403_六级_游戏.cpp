#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 2e5 + 5;
const int MOD = 1e9 + 7;

int n, a, b, c;
int v[N];

int dfs(int x) {
    if (x <= c) return 1;
    if (v[x] != 0) return v[x];
    v[x] = (dfs(x - a) % MOD + dfs(x - b) % MOD) % MOD;
    return v[x];
}

void solve() {
    cin >> n >> a >> b >> c;
    cout << dfs(n);
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