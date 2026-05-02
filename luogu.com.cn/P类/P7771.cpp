#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> g[N], ans;
int in[N], cur[N];
void dfs(int u)
{
    while (cur[u] < g[u].size()) {
        int v = g[u][cur[u]++];
        dfs(v);
    }
    ans.push_back(u);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        in[v]++;
    }
    for (int i = 1; i <= n; i++)
        sort(g[i].begin(), g[i].end());
    int st = 0, ed = 0, st_idx = 1;
    for (int i = 1; i <= n; i++) {
        const int gi_size = g[i].size();
        if (in[i] == gi_size)
            continue;
        if (in[i] - gi_size == 1)
            ed++;
        else if (gi_size - in[i] == 1) {
            st++;
            st_idx = i;
        } else {
            cout << "No\n";
            return 0;
        }
    }
    if (st == 1 && ed == 1 || st == 0 && ed == 0) {
        dfs(st_idx);
        for (int i = ans.size() - 1; i >= 0; i--)
            cout << ans[i] << " ";
    } else
        cout << "No\n";
}