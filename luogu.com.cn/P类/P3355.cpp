#include <bits/stdc++.h>
#define debug(...) cerr << #__VA_ARGS__ << " = " << __VA_ARGS__ << endl;
#define IAK std::ios::sync_with_stdio(false);
#define IOI std::cin.tie(nullptr)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<long, long>;

const int N = 205;

int id[N][N];
int dx[] = { -1, -2, -2, -1, 1, 2, 2, 1 }, dy[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int n, q;
bool vis[N * N];
int match[N * N];

struct Edge {
    int to;
    int next;
} edge[int(9e6)];

int head[int(9e6)];
int tot;

void init()
{
    memset(head, -1, sizeof(head));
    tot = 0;
}

void addEdge(int u, int v)
{
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}

bool inside(int x, int y)
{
    return (x >= 1 && y >= 1 && x <= n && y <= n);
}

bool dfs(int u)
{
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].to;
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

void solve()
{
    cin >> n >> q;
    init();
    while (q--) {
        int x, y;
        cin >> x >> y;
        id[x][y] = -1;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (id[i][j] != -1) {
                id[i][j] = ++cnt;
            }
        }
    }
    int xn = cnt;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (id[i][j] != -1 && (i + j) % 2) {
                for (int k = 0; k < 8; k++) {
                    int nx = i + dx[k], ny = j + dy[k];
                    if (inside(nx, ny) && id[nx][ny] != -1) {
                        addEdge(id[i][j], id[nx][ny]);
                    }
                }
            }
        }
    }
    cnt = 0;
    for (int i = 1; i <= xn; i++) {
        memset(vis, 0, sizeof vis);
        if (dfs(i))
            cnt++;
    }
    cout << xn - cnt;
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