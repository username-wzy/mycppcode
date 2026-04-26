#include <bits/stdc++.h>

int n, m;

bool g[2005][2005], book[1005];
int a[1005], res[2005], in[2005];

void toposort()
{
    std::queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0)
            q.push(i);
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 1; v <= n; v++) {
            if (g[u][v]) {
                if (v > n)
                    res[v] = std::max(res[v], res[u]);
                else
                    res[v] = std::max(res[v], res[u] + 1);
                in[v]--;
                if (in[v] == 0)
                    q.push(v);
            }
        }
    }
}

int main()
{
    std::cin >> n >> m;
    for (int _ = 1; _ <= m; _++) {
        int x;
        std::cin >> x;
        memset(book, 0, sizeof book);
        for (int i = 1; i <= x; i++) {
            std::cin >> a[i];
            book[a[i]] = 1;
            for (int i = a[1]; i <= a[x]; i++) {
                if (book[i]) {
                    for (int j = a[1]; j <= a[x]; j++) {
                        if (!book[j] && g[i][j] == false) {
                            g[j][i] = 1;
                            in[i]++;
                        }
                    }
                }
            }
        }
    }
    toposort();
    int maxn = 0;
    for (int i = 1; i <= n; i++) {
        maxn = std::max(maxn, res[i] + 1);
    }
    std::cout << maxn;
    return 0;
}