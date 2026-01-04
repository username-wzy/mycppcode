#include<bits/stdc++.h>
#define ll long long

using namespace std;

int n, a[100005], trie[100005 * 32][2], idx;
vector<pair<int, int>> g[100005];
string s[100005];

void dfs(int u, int fa) {
    for (auto p : g[u]) {
        int v = p.first, w = p.second;
        if (v != fa) {
            a[v] = a[u] ^ w; 
            dfs(v, u);     
        }    
    }
}

void insert(string &s) {
    int p = 0;
    for (auto s_i : s) {
        auto x = s_i - '0';
        if (!trie[p][x]) trie[p][x] = ++idx;
        p = trie[p][x];
    }
}

int find(string &s) {
    int p = 0, ans = 0;
    for (auto s_i : s) {
        auto x = s_i - '0';
        if (trie[p][!x]) ans = ans * 2 + 1, p = trie[p][!x];
        else ans *= 2, p = trie[p][x];
    }
    return ans;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    dfs(1, -1);
    for (int i = 1; i <= n; i++) {
        bitset<32> bs(a[i]);
        s[i] = bs.to_string();
        insert(s[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, find(s[i]));
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