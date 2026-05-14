#include <bits/stdc++.h>
#define debug(...) cerr << #__VA_ARGS__ << " = " << __VA_ARGS__ << endl;
#define IAK std::ios::sync_with_stdio(false);
#define IOI std::cin.tie(nullptr)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<long, long>;

vector<pair<int, int>> dot;
int fa[55], n;

int find(int x)
{
    return (fa[x] == x ? x : fa[x] = find(fa[x]));
}

bool unite(int x, int y)
{
    int rx = find(x), ry = find(y);
    if (rx != ry) {
        fa[rx] = ry;
        return true;
    }
    return false;
}

bool check(int time)
{
    for (int i = 0; i < n; i++)
        fa[i] = i;
    for (int i = 0; i < dot.size(); i++) {
        for (int j = i + 1; j < dot.size(); j++) {
            auto p1 = dot[i];
            auto p2 = dot[j];
            int x1 = p1.first, y1 = p1.second, x2 = p2.first, y2 = p2.second;
            int d = abs(x1 - x2) + abs(y1 - y2);
            if (d <= time * 2) {
                unite(i, j);
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (fa[i] == i)
            cnt++;
    }
    return (cnt == 1);
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        dot.push_back({ x, y });
    }
    ll l = 0, r = 1e15;
    int ans = 0;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (check(mid)) {
            r = mid - 1;
            ans = mid;
        } else
            l = mid + 1;
    }
    cout << ans;
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