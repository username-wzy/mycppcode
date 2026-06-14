#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << '\n';
#define IAK std::ios::sync_with_stdio(false);
#define IOI std::cin.tie(nullptr)

using namespace std;
typedef long long ll;

constexpr int N = 5e5 + 5;

class LCA {
private:
    int n;
    int log_n;
    vector<int> dep;
    vector<vector<int>> up;
    vector<int> diff;
    vector<vector<int>> adj;
    void dfs(int u, int fa, int d)
    {
        dep[u] = d;
        up[u][0] = fa;
        for (int j = 1; j <= log_n; j++)
            up[u][j] = up[up[u][j - 1]][j - 1];
        for (int v : adj[u])
            if (v != fa)
                dfs(v, u, d + 1);
    }
    void toGetSum(int u, int fa, vector<int>& res)
    {
        for (int v : adj[u]) {
            if (v != fa) {
                toGetSum(v, u, res);
                res[u] += res[v];
            }
        }
    }

public:
    LCA(int n, int root, vector<vector<int>>& adj)
    {
        this->n = n;
        this->log_n = ceil(log2(n));
        this->adj = adj;
        dep.resize(n + 1, 0);
        up.resize(n + 1, vector<int>(log_n + 1));
        diff.resize(n + 1, 0);
        dfs(root, 0, 0);
    }
    int getLCA(int u, int v)
    {
        if (dep[u] < dep[v]) {
            swap(u, v);
        }
        for (int j = log_n; j >= 0; j--) {
            if (dep[u] - (1 << j) >= dep[v]) {
                u = up[u][j];
            }
        }
        if (u == v) {
            return u;
        }
        for (int j = log_n; j >= 0; j--) {
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }
        return up[u][0];
    }
    int getDepth(int u)
    {
        return dep[u];
    }
    int getDist(int u, int v)
    {
        return dep[u] + dep[v] - 2 * dep[getLCA(u, v)];
    }
    void add(int u, int v)
    {
        diff[u]++, diff[v]++, diff[getLCA(u, v)]--, diff[up[getLCA(u, v)][0]]--;
    }
    vector<int> getSum(int root)
    {
        vector<int> res(diff);
        toGetSum(root, up[root][0], res);
        return res;
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    LCA lca(n, 1, adj);
    while (q--) {
        int s, t;
        cin >> s >> t;
        lca.add(s, t);
    }
    vector<int> res = lca.getSum(1);
    cout << *max_element(res.begin(), res.end()) << '\n';
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