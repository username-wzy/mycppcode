#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

constexpr int N = 2e5 + 5;

int a[N];
bool ok[N];
vector<int> g[N];
unordered_map<int, int> cnt;
int total = 0;
int n;

void dfs(int u, int fa = 0)
{
    if (++cnt[a[u]] == 2) {
        total++;
    }

    ok[u] = (total > 0);

    for (auto v : g[u]) {
        if (v != fa) {
            dfs(v, u);
        }
    }

    cnt[a[u]]--;
    if (cnt[a[u]] == 1) {
        total--;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
        cout << (ok[i] ? "Yes" : "No") << '\n';
    return 0;
}