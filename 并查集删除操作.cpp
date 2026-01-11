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

int deep[1400005], fa[1400005], cnt = 0;

int find(int x)
{
    return (fa[x] == x) ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y)
{
    int fx = find(x), fy = find(y);
    if (fx != fy) {
        fa[fy] = fx;
    }
}

void erase(int x)
{
    fa[x] = ++cnt;
    fa[cnt] = cnt;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    cnt = 2 * n;
    for (int i = 1; i <= n; i++) {
        fa[i] = n + i;
        fa[n + i] = n + i;
        deep[i] = 1;
        deep[n + i] = 1;
    }
    for (int i = 1; i <= m; i++) {
        short op;
        cin >> op;
        int x, y;
        cin >> x;
        if (op == 1) {
            cin >> y;
            merge(x, y);
        } else if (op == 2) {
            cin >> y;
            if (find(x) == find(y)) {
                cout << "Y\n";
            } else
                cout << "N\n";
        } else {
            erase(x);
        }
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