#include <bits/stdc++.h>

const int N = 3e4 + 5;

std::vector<int> g[N];

int book[N];
std::bitset<N> go[N];

void toposort(int idx)
{
    if (book[idx])
        return;
    book[idx] = 1;
    for (int v : g[idx]) {
        toposort(v);
        go[idx] |= go[v];
    }
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        std::cin >> u >> v;
        g[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        go[i].set(i);
    }
    for (int i = 1; i <= n; i++) {
        toposort(i);
    }
    for (int i = 1; i <= n; i++) {
        std::cout << go[i].count() << '\n';
    }
    return 0;
}