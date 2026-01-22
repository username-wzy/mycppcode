#include<bits/stdc++.h>
#define ll long long

using namespace std;

int g[100005][26], cnt[100005], idx;

void insert(string &s) {
    int u = 0;
    for (auto si : s) {
        int v = si - 'a';
        if (!g[u][v]) g[u][v] = ++idx;
        u = g[u][v];
    }
    cnt[u]++;
}

short find(string &s) {
    int u = 0;
    for (auto si : s) {
        int v = si - 'a';
        if (!g[u][v]) return 0;
        u = g[u][v];
    }
    return cnt[u];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        char c;
        string s;
        cin >> c >> s;
        if (c == 'I') {
            insert(s);
        } else cout << find(s) << '\n';
    }
    return 0;
}