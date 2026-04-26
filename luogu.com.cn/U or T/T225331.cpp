#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

constexpr int N = 1e5 + 5;
constexpr int inf = 0x3f3f3f3f;

vector<int> graph[N];
int prefix[N];
int ans = inf;
int n;

void dfs(int u, int fa)
{
    prefix[u] = 1;
    int max_part = 0;
    for (int v : graph[u]) {
        if (v == fa)
            continue;
        dfs(v, u);
        prefix[u] += prefix[v];
        max_part = max(max_part, prefix[v]);
    }
    max_part = max(max_part, n - prefix[u]);
    ans = min(max_part, ans);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1, 0);

    cout << ans;
    return 0;
}