#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    int best = INT_MAX;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        best = min(best, x);
    }
    ll result = 0;
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        result += best * x;
    }
    cout << result << '\n';
    return 0;
}
