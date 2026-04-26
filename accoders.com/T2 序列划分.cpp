#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a;
    a.reserve(n);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }

    ll sum = 0;
    int cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
        sum += a[i];
        if (sum >= 0) {
            sum = 0;
            cnt++;
        }
    }
    if (sum < 0) {
        cout << -1;
    } else {
        cout << cnt;
    }
    return 0;
}