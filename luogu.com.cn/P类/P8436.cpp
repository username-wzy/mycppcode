#include <bits/stdc++.h>
#define debug(...) cerr << #__VA_ARGS__ << " = " << __VA_ARGS__ << endl;
#define IAK std::ios::sync_with_stdio(false);
#define IOI std::cin.tie(nullptr)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<long, long>;

const int N = 5e5 + 5;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> dfn(n + 1), low(n + 1);
    int timer = 0, cnt = 0;
    stack<int> stk;
    vector<vector<int>> dcc(n + 1);
    auto tarjan = [&](auto&& self, int u, int fa) -> void {
        dfn[u] = low[u] = ++timer;
        stk.push(u);
        bool flag = 0;
        for (auto v : g[u]) {
            if (v == fa && flag == 0) {
                flag = 1;
                continue;
            }
            if (dfn[v] == 0) {
                self(self, v, u);
                low[u] = min(low[u], low[v]);
            } else
                low[u] = min(low[u], dfn[v]);
        }
        if (dfn[u] == low[u]) {
            cnt++;
            int v;
            do {
                v = stk.top();
                stk.pop();
                dcc[cnt].push_back(v);
            } while (v != u);
        }
    };

    for (int i = 1; i <= n; i++) {
        if (dfn[i])
            continue;
        tarjan(tarjan, i, 0);
    }
    cout << cnt << '\n';
    for (int i = 1; i <= cnt; i++) {
        cout << dcc[i].size() << ' ';
        for (auto u : dcc[i]) {
            cout << u << ' ';
        }
        cout << '\n';
    }
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