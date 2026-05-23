#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << '\n';
#define IAK std::ios::sync_with_stdio(false);
#define IOI std::cin.tie(nullptr)

using namespace std;
typedef long long ll;

constexpr int N = 5e5 + 5;

vector<int> g[N];
vector<pair<int, int>> query[N];
int fa[N], ans[N];
bool vis[N];

int find(int x)
{
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

bool merge(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return false;
    fa[x] = y;
    return true;
}

void tarjan(int u)
{
    vis[u] = true;
    for (int v : g[u]) {
        if (vis[v])
            continue;
        tarjan(v);
        merge(v, u);
    }
    for (int i = 0; i < query[u].size(); i++) {
        int v = query[u][i].first;
        int id = query[u][i].second;
        if (vis[v])
            ans[id] = find(v);
    }
}

void solve()
{
    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        if (u == v)
            ans[i] = u;
        else {
            query[u].emplace_back(v, i);
            query[v].emplace_back(u, i);
        }
    }

    tarjan(s);

    for (int i = 1; i <= m; i++)
        cout << ans[i] << '\n';
}

int main()
{
    IAK IOI;
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}