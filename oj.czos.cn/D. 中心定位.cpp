#include <bits/stdc++.h>
#define IAK std::ios::sync_with_stdio(false);
#define IOI std::cin.tie(nullptr)
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    vector<array<ll, 3>> message;
    for (int i = 1; i <= n; i++) {
        ll x, y, t;
        cin >> x >> y >> t;
        message.push_back({ x, y, t });
    }

    if (n == 1) {
        cout << message[0][0] << " " << message[0][1] << " " << message[0][2];
        return;
    }
    for (ll i = 0; i <= 100; i++) {
        for (ll j = 0; j <= 100; j++) {
            ll h = -1;
            bool flag = true;
            for (int k = 0; k < n; k++) {
                auto p = message[k];
                ll x = p[0], y = p[1], t = p[2];
                ll d = llabs(x - i) + llabs(y - j);
                if (t > 0) {
                    if (h == -1)
                        h = t + d;
                    else if (h != t + d) {
                        flag = false;
                        break;
                    }
                } else {
                    if (h > d) {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag && h > 0) {
                cout << i << " " << j << " " << h << "\n";
                return;
            }
        }
    }
}

int main()
{
    IAK IOI;
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}