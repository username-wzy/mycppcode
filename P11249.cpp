#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> g[N];
int in[N];
bool a[N], lj[N];

void solve()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        g[i].clear();   
        lj[i] = true;
        cin >> a[i];
        in[i] = 0;
    }

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        in[u]++, in[v]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!a[i] && in[i] == 1)
            q.push(i);
    }

    // 剪枝
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        lj[u] = false;
        for (int v : g[u]) {
            if (!lj[v])
                continue;
            in[v]--;
            if (!a[v] && in[v] == 1)
                q.push(v);
        }
    }

    // 统计叶子
    int leaf = 0;
    for (int i = 1; i <= n; i++) {
        if (lj[i] && in[i] == 1)
            leaf++;
    }

    cout << (leaf <= 2 ? "Yes\n" : "No\n");
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
        solve();

    return 0;
}