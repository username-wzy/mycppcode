#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, k;
    cin >> n >> k;
    ll mx = -1;
    int id = 1;
    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        if (x > mx) {
            mx = x;
            id = i;
        }
    }
    cout << id;

    return 0;
}
