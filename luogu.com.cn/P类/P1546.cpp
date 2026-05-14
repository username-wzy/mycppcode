#include <bits/stdc++.h>
#define debug(...) cerr << #__VA_ARGS__ << " = " << __VA_ARGS__ << endl;
#define IAK std::ios::sync_with_stdio(false);
#define IOI std::cin.tie(nullptr)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<long, long>;

int fa[105];

void init(int n)
{
    for (int i = 1; i <= n; i++)
        fa[i] = i;
}

int find(int x)
{
    return (fa[x] == x ? x : fa[x] = find(fa[x]));
}

bool unite(int x, int y)
{
    int rx = find(x), ry = find(y);
    if (rx == ry)
        return false;
    fa[rx] = ry;
    return true;
}

void solve()
{
    int n;
    cin >> n;
    vector<array<int, 3>> edge;
    init(n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            if (i == j) {
                continue;
            }
            edge.push_back({ x, i, j });
        }
    }
    sort(edge.begin(), edge.end());
    ll W = 0;
    int cnt = 0;
    for (int i = 0; i < edge.size(); i++) {
        auto [w, u, v] = edge[i];
        if (unite(u, v)) {
            cnt++;
            W += w;
        }
        if (cnt == n - 1) {
            cout << W;
            return;
        }
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