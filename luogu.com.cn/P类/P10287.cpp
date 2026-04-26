#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e5 + 5;

constexpr int ai_size = 10 + 5;

int f[N][ai_size], in[N];
short a[N];

vector<int> g[N];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        in[v]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0)
            q.push(i);
        f[i][a[i]] = 1;
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            in[v]--;
            if (in[v] == 0)
                q.push(v);
            // 第一种
            for (int i = 1; i <= a[v]; i++) {
                f[v][a[v]] = max(f[v][a[v]], f[u][i] + 1);
            }
            // 第二种
            for (int i = 1; i <= 10; i++) {
                f[v][i] = max(f[v][i], f[u][i]);
            }
        }
    }
    int maxn = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 10; j++) {
            maxn = max(f[i][j], maxn);
        }
    }
    cout << maxn;
    return 0;
}