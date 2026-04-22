#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int l[15], r[15];
int n, ans = 0;

void dfs(int u, int sum)
{
    if (u == n) {
        ans = max(sum, ans);
        return;
    }
    dfs(u + 1, sum);
    int v = u + 1;
    int l1 = l[u], l2 = l[v], r1 = r[u], r2 = r[v];
    if (l2 <= r1 && l1 <= r2 && ((l1 == l2 || l1 == r2) || (r1 == l2 || r1 == r2))) {
        dfs(u + 1, sum + 1);
    }
}

void solve()
{
    memset(l, 0, sizeof(l));
    memset(r, 0, sizeof(r));
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
    }
    ans = 0;
    dfs(1, 0);
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}