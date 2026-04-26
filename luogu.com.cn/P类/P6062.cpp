#include<bits/stdc++.h>
#define ll long long

using namespace std;

char a[55][55];
vector<int> g[2505];
bool vis[2505];
int match[2505];

pair<int, int> hw[55][55];

bool dfs(int u) {
    for(auto v : g[u]) {
        if (!vis[v]) {
            vis[v] = true;
            if (!match[v] || dfs(match[v])) {
                match[v] = u;
                return 1;
            }
        }
    }
    return 0;
}

void solve() {
    int r, c, idx = 0;
    cin >> r >> c;
    for (int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            cin >> a[i][j];
            if (a[i][j] == '*') {
                if (a[i][j - 1] != '*') {
                    hw[i][j].first = ++idx;
                } else hw[i][j].first = idx;
            }
        }
    }
    int idx2 = 0;
    for (int i = 1; i <= c; i++) {
        for (int j = 1; j <= r; j++) {
            if (a[j][i] == '*') {
                if (a[j - 1][i] != '*') {
                    hw[j][i].second = ++idx2;
                } else hw[j][i].second = idx2;
                g[hw[j][i].first].push_back(hw[j][i].second);
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= idx; i++) {
        memset(vis, 0, sizeof(vis));
        cnt += dfs(i);
    }
    cout << cnt;
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