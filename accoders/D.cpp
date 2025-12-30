#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 4 * 1e5 + 5;

int a[N], trie[N * 30][2], d[N], e[N], ans, idx, n;
bitset<30> bs;

void insert(string &s) {
    int p = 0;
    for (auto c : s) {
        bool x = c - '0';
        if (!trie[p][x]) trie[p][x] = ++idx;
        p = trie[p][x];
    }
}

int query(string &s) {
    int p = 0, res = 0;
    for (char c : s) {
        bool x = c - '0';
        if (trie[p][!x]) res = res * 2 + 1, p = trie[p][!x];
        else res *= 2, p = trie[p][x];
    }
    return res;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        bs = a[i];
        string temp = bs.to_string();
        insert(temp);
        d[i] = query(temp);
    }
    memset(trie, 0, sizeof(trie));
    idx = 0;
    for (int i = n; i >= 1; i--) {
        bs = a[i];
        string temp = bs.to_string();
        insert(temp);
        e[i] = query(temp);
        e[i] = max(e[i + 1], e[i]);
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        ans = max(ans, d[i] + e[i + 1]);
    }
    cout << ans;
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