#include <bits/stdc++.h>
#define debug(x) do { cerr << #x << " = " << x << '\n'; } while(0)
#define IAK std::ios::sync_with_stdio(false);
#define IOI std::cin.tie(nullptr)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<long, long>;

const int N = 1e5 + 5;

int n;
vector<int> g[N];
int eular_ord[N], cap = 0, dep[N];

void dfs()
{
    stack<tuple<int, int, bool>> stk;  // (node, parent, is_exit)
    stk.emplace(1, 0, false);
    while (!stk.empty()) {
        auto [u, fa, is_exit] = stk.top();
        stk.pop();
        if (is_exit) {
            eular_ord[++cap] = u;
        } else {
            eular_ord[++cap] = u;
            dep[u] = dep[fa] + 1;
            for (auto it = g[u].rbegin(); it != g[u].rend(); ++it) {
                int v = *it;
                if (v != fa) {
                    stk.emplace(u, 0, true);
                    stk.emplace(v, u, false);
                }
            }
        }
    }
}

void solve()
{
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs();
    for (int i = 1; i <= cap; i++)
        cout << eular_ord[i] << " ";
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