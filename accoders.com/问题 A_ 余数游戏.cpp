#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

constexpr int N = 3005;

int a[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, l, r;
    cin >> n >> l >> r;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int ans = 1e9, res = 0;

    for (int k = l; k <= r; k++) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            cnt += a[i] % k;
        }
        if (cnt < ans) {
            ans = cnt;
            res = k;
        }
    }

    cout << res << '\n';
    return 0;
}