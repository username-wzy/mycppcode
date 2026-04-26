#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct node {
    int x, y, t;
    bool operator<(const node other) const
    {
        return t < other.t;
    }
} a[1005];

int siz[1005], fa[1005];

int find(int x)
{
    return (fa[x] == x) ? x : find(fa[x]);
}

void merge(int x, int y, int& n, int& cnt, int& t)
{
    int fx = find(x), fy = find(y);
    if (fx == fy)
        return;
    if (siz[fx] < siz[fy]) {
        fa[fx] = fy;
        siz[fy] += fx;
        if (siz[fy] >= n) {
            cout << cnt + t;
            exit(0);
        }
    } else {
        fa[fy] = fx;
        siz[fx] += fy;
        if (siz[fx] >= n) {
            cout << cnt + t;
            exit(0);
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i].x >> a[i].y >> a[i].t;
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        siz[i] = 1;
    }
    int cnt = 0;
    for (int i = 1; i <= m; i++) {
        merge(a[i].x, a[i].y, n, cnt, a[i].t);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // freopen("xxx.in", "r", stdin);
    // freopen("xxx.out", "w", stdout);

    int T = 1; // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}