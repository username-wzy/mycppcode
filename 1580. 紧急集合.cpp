#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int head[500005], nxt[1000005], to[1000005], tot;
void add_edge(int u, int v)
{
    to[++tot] = v;
    nxt[tot] = head[u];
    head[u] = tot;
}
int n;
int dep[500005];
int fa[500005][20];

void pre_bfs()
{
    queue<int> q;
    q.push(1);
    dep[1] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i; i = nxt[i]) {
            int v = to[i];
            if (dep[v] == 0) {
                dep[v] = dep[u] + 1;
                q.push(v);
                fa[v][0] = u;
            }
        }
    }
}

void LCA_pre()
{
    for (int i = 1; i <= 19; i++)
        for (int u = 1; u <= n; u++)
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
}

int get_LCA(int u, int v)
{
    if (dep[u] < dep[v])
        swap(u, v);

    for (int i = 19; i >= 0; i--) {
        if (dep[fa[u][i]] >= dep[v])
            u = fa[u][i];
    }

    if (u == v)
        return u;

    for (int i = 19; i >= 0; i--) {
        if (fa[u][i] != fa[v][i]) {
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    return fa[u][0];
}

int main()
{
    int q;
    scanf("%d %d", &n, &q);

    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }

    pre_bfs();
    LCA_pre();

    for (int i = 1; i <= q; i++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        int a = get_LCA(x, y);
        int b = get_LCA(y, z);
        int c = get_LCA(x, z);

        int p;
        if (dep[a] >= dep[b] && dep[a] >= dep[c])
            p = a;
        else if (dep[b] >= dep[a] && dep[b] >= dep[c])
            p = b;
        else
            p = c;

        ll ans = (ll)dep[x] + dep[y] + dep[z] - (ll)dep[a] - dep[b] - dep[c];

        printf("%d %lld\n", p, ans);
    }
    return 0;
}
