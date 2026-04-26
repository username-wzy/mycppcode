#include <bits/stdc++.h>
using namespace std;

const int N = 3e4 + 5;

int n, m;
vector<int> g[N];
int in[N];
vector<int> topo;
bitset<N> bs[N];

void toposort() {
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (in[i] == 0)
            q.push(i);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for (int v : g[u]) {
            if (--in[v] == 0)
                q.push(v);
        }
    }

    for (int i = topo.size() - 1; i >= 0; i--) {
        int u = topo[i];
        bs[u].set(u);
        for (int v : g[u]) {
            bs[u] |= bs[v];
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << bs[i].count() << '\n';
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        in[v]++;
    }
   
    toposort();
    return 0;
}
