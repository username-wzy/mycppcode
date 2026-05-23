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
    std::vector<int> depth;
    std::vector<std::vector<int>> up;
    void dfs(int u, int fa, int d, const std::vector<std::vector<int>>& adj)
    {
        depth[u] = d;
        up[u][0] = fa;
        for (int j = 1; j <= log_n; ++j) {
            if (up[u][j - 1] != -1) {
                up[u][j] = up[up[u][j - 1]][j - 1];
            } else {
                up[u][j] = -1;
            }
        }
        for (int v : adj[u]) {
            if (v != fa) {
                dfs(v, u, d + 1, adj);
            }
        }
    }

public:
    LCA(int n, int root, const std::vector<std::vector<int>>& adj)
    {
        this->n = n;
        this->log_n = std::ceil(std::log2(n));

        depth.assign(n, 0);
        up.assign(n, std::vector<int>(log_n + 1, -1));

        dfs(root, -1, 0, adj);
    }
    int getLCA(int u, int v)
    {
        if (depth[u] < depth[v]) {
            std::swap(u, v);
        }
        for (int j = log_n; j >= 0; --j) {
            if (depth[u] - (1 << j) >= depth[v]) {
                u = up[u][j];
            }
        }
        if (u == v) {
            return u;
        }
        for (int j = log_n; j >= 0; --j) {
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }
        return up[u][0];
    }
    int getDepth(int u) const
    {
        return depth[u];
    }
};

void solve()
{
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