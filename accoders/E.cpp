#include<bits/stdc++.h>
#define ll long long

using namespace std;

int g[100005][2], idx;
bool cnt[100005];

bool insert(string &s) {
    int u = 0;
    for (auto si : s) {
        bool v = si - '0';
        if (!g[u][v]) g[u][v] = ++idx;
        if (cnt[u]) return 1;
        u = g[u][v];
    }
    cnt[u] = 1;
    return 0;
}

void solve() {
    int T = 1;
    bool flag = true;
    string s;
    while (cin >> s) {
        if (s == "9") {
            if (flag) printf("Set %d is immediately decodable\n", T);
            else printf("Set %d is not immediately decodable\n", T);
            memset(g, 0, sizeof(g));
            memset(cnt, 0, sizeof(cnt));
            T++;
            flag = true;
        } else {
            if (flag && insert(s)) flag = 0;
        }
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