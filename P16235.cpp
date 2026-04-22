#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve()
{
    int n;
    ll sum = 0;
    cin >> n;
    static ll a[int(2e5 + 5)];
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[i] = x;
        sum += x;
    }
    if (sum % 5 != 0) {
        cout << "F\n";
    } else {
        for (int i = 1; i <= n; i++) {
            if (a[i] * 5 > sum) {
                cout << "F\n";
                return;
            }
        }
        cout << "T\n";
    }
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