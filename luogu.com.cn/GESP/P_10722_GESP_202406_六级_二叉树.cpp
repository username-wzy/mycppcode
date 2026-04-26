#include<bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> g[100005];
bool a[100005], f[100005];

void solve() {
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int x; cin >> x;
        g[x].push_back(i);
    }
    string s; cin >> s;
    for (int i = 1; i <= n; i++) {
        a[i] = s[i - 1] - '0';
    }
    int q; cin >> q;
    while (q--) {
        int x;
        cin >> x;
        f[x]++;
    }
    for (int i = )
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