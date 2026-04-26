#include <iostream>
#include <queue>
#include <vector>

std::vector<int> g[10005];
int in[10005];
int n, m;
int ans[10005];

void toposort()
{
    std::queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!in[i]) {
            q.push(i);
        }
    }
    int count = 0, sum = 0;
    const int jj = 100;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        count++;
        sum += jj + ans[u];
        for (auto v : g[u]) {
            in[v]--;
            ans[v] = std::max(ans[v], ans[u] + 1);
            if (!in[v]) {
                q.push(v);
            }
        }
    }
    if (count < n) {
        std::cout << "Poor Xed";
    } else
        std::cout << sum;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);

    std::cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        std::cin >> u >> v;
        g[v].push_back(u);
        in[u]++;
    }
    toposort();
    return 0;
}