#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
constexpr int N = 2e5 + 5;

int a[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + 1 + n);

    int cnt = 0;

    for (int i = 2; i < n; i++) {
        if (a[i] - a[i - 1] <= m || a[i + 1] - a[i] <= m)
            cnt++;
    }

    if (a[2] - a[1] <= m) {
        cnt++;
    }

    if (a[n] - a[n - 1] <= m) {
        cnt++;
    }

    cout << cnt;
    return 0;
}
