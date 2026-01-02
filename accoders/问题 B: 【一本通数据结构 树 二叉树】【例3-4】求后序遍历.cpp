#include<bits/stdc++.h>
#define ll long long

using namespace std;

string s, t;

void dfs(int sl, int sr, int tl, int tr) {
    int x = 0;
    for (int i = tl; i <= tr; i++) {
        if (t[i] == s[sl]) {
            x = i;
            break;
        }
    }
    if (x > tl) dfs(sl + 1, x - tl + sl, tl, x - 1);
    if (tr > x) dfs(x - tl + sl + 1, sr, x + 1, tr);
    cout << s[sl];
}

void solve() {
    cin >> s >> t;
    dfs(0, s.size() - 1, 0, t.size() - 1);
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