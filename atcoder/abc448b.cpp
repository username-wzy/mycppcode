#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> c(m);
    for (int i = 0; i < m; i++)
        cin >> c[i];
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        int use = min(c[a - 1], b);
        ans += use;
        c[a - 1] -= use;
    }
    cout << ans;
    return 0;
}