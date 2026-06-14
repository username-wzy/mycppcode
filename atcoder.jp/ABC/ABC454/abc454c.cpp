#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 3e5 + 5;

vector<int> g[N];

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
    }

    queue<int> q;
    static bool vis[N];

    vis[1] = true;
    q.push(1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
    }

    cout << accumulate(vis + 1, vis + n + 1, 0);
    return 0;
}