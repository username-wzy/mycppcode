#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << '\n';
#define IAK std::ios::sync_with_stdio(false);
#define IOI std::cin.tie(nullptr)
using namespace std;

constexpr int N = 1e5 + 5;

int color[N];
vector<int> adj[N];
int cnt = 0;

bool dfs(const int u, const int fa)
{
    bool nxt_color = false;
    for (const int& v : adj[u]) {
        if (v == fa)
            continue;
        if (dfs(v, u)) {
            nxt_color = true;
        }
    }
    if (nxt_color && color[u] == 0) {
        // 因为根节点是黑，子树是黑，当前是白，属于黑白黑，为了保证树连通就要变为黑
        cnt++;
        color[u] = 1;
    }
    return (color[u] || nxt_color);
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> color[i];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int start = -1;
    for (int i = 1; i <= n; i++)
        if (color[i] == 1)
            start = i;
    if (start == -1)
        cout << 0;
    else {
        dfs(start, -1);
        cout << cnt;
    }
}

int main()
{
    IAK IOI;
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}