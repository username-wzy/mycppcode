#include<bits/stdc++.h>
#define ll long long

using namespace std;

int cnta[500005], cntb[500005], g[500005][2], idx = 0;

void insert(string &s) {
    int p = 0;
    for (auto si : s) {
        bool x = si - '0';
        if (!g[p][x]) g[p][x] = ++idx;
        p = g[p][x];
        cnta[p]++;
    }
    cnta[p]--;
    cntb[p]++;
}

int find(string &s, int ansi) {
    int p = 0, ans = 0;
    for (auto si : s) {
        bool x = si - '0';
        if (!g[p][x]) return ans;
        p = g[p][x];
        ans += cntb[p];
    }
    return ans + cnta[p];
}

void solve() {
    int n, m;
    cin >> n >> m;
    while (n--) {
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
    for (int i = 1; i <= m; i++) {
        string s;
        int siz;
        cin >> siz;
        for (int i = 0; i < siz; i++) {
            char c;
            cin >> c;
            s.push_back(c);
        }
        cout << find(s, i) << '\n';
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