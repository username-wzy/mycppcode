#include<bits/stdc++.h>
#define ll long long

using namespace std;

int cnta[500005], cntb[500005], g[500005][2], idx = 0, ans[500005];

void insert(string &s) {
    int p = 0;
    for (char c : s) {
        bool x = c - '0';
        if (!g[p][x]) g[p][x] = ++idx;
        p = g[p][x];
        cnta[p]++;
    }
    cntb[p]++;
    cnta[p]--;
}

void find(string &s, int ansi) {
    int p = 0;
    for (char c : s) {
        bool x = c - '0';
        if (g[p][x]) ans[ansi] += cntb[g[p][x]];
        else return ;
        p = g[p][x];
    } 
    ans[ansi] += cnta[p];
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string s;
        int siz;
        cin >> siz;
        for (int i = 0; i < siz; i++) {
            char c;
            cin >> c;
            s.push_back(c);
        }
        insert(s);
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << cnta[i] << " " << cntb[i] << '\n';
    // }
    for (int i = 1; i <= m; i++) {
        string s;
        int siz;
        cin >> siz;
        for (int i = 0; i < siz; i++) {
            char c;
            cin >> c;
            s.push_back(c);
        }
        find(s, i);
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << "\n";
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