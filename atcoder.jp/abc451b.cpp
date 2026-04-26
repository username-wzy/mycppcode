#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        a[x]++, b[y]++;
    }
    for (int i = 1; i <= m; i++) {
        cout << b[i] - a[i] << '\n';
    }
    return 0;
}