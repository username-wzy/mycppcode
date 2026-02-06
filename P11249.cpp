#include <bits/stdc++.h>
#define ll long long

using namespace std;

constexpr int N = 1e5 + 5;

vector<int> g[N];
bool a[N], bxd;
int bw_count = 0;

ll dfs(int u, int fa)
{
    int x = a[u]; // 记录以u为根节点的子树的宝物总数，自己的宝物也算
    int y = 0; // 记录以u的子节点为根节点的有宝物的子树个数
    for (int v : g[u]) {
        if (v != fa) {
            int x = dfs(v, u); // 以v为根节点的子树的宝物总数
            if (x >= 1) {
                x += x;
                y++;
            }
        }
    }
    if ((x != bw_count && y > 1) || y > 2) { // 有宝物的子树个数>2时必然走完两个子树，第三，四...个子树就走不了
        bxd = 1;
    }
    return x;
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        g[i].clear();
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        bw_count += a[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1);
    if (!bxd)
        cout << "Yes\n";
    else
        cout << "No\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T = 1;
    cin >> T;
    while (T--)
        solve();

    return 0;
}   