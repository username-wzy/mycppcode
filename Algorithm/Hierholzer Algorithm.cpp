#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

constexpr int N = 50005;
constexpr int M = 100005;
    
int idx[N]; // 用来记录每个点已经处理到第几条边
bool vis[M];
vector<pair<int, int>> g[N];
vector<int> res_E, res_V;

void dfs(int u)
{
    while (idx[u] < g[u].size()) {
        int v = g[u][idx[u]].first, e = g[u][idx[u]].second;
        idx[u]++;
        if (!vis[e]) {
            vis[e] = true;
            dfs(v);
            res_E.push_back(e);
        }
    }
    res_V.push_back(u);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // do sth
    return 0;
}