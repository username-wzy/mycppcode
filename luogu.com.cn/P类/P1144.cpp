#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << '\n';
#define IAK std::ios::sync_with_stdio(false);
#define IOI std::cin.tie(nullptr)

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

vector<int> g[1000005];
int ans[1000005];
bool in_que[1000005];

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, y;
        cin >> u >> y;
        g[u].push_back(y);
        g[y].push_back(u);
    }
    queue<int> q;
    vector<int> dis(n + 1, 1e9);
    q.push(1);
    dis[1] = 1;
    ans[1] = 1;
    in_que[1] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        in_que[u] = 0;
        for (int v : g[u]) {
            if (dis[u] + 1 < dis[v]) {
                dis[v] = dis[u] + 1;
                if (!in_que[v])
                    q.push(v);
                ans[v] = ans[u];
            } else if (dis[u] + 1 == dis[v]) {
                ans[v] = (ans[v] + ans[u]) % (ll)(1e5 + 3);
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << "\n";
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