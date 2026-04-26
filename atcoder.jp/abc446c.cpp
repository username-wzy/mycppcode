#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto solve = [&]() {
        int n, d;
        cin >> n >> d;
        vector<ll> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }

        deque<pair<ll, ll>> q;
        for (int i = 1; i <= n; i++) {
            if (a[i] > 0) {
                q.push_back({ i, a[i] });
            }

            int need = b[i];
            while (need > 0) {
                auto& t = q.front();
                if (t.second <= need) {
                    need -= t.second;
                    q.pop_front();
                } else {
                    t.second -= need;
                    need = 0;
                }
            }

            ll lim = i - d;
            while (!q.empty() && q.front().first <= lim)
                q.pop_front();
        }

        int ans = 0;
        for (auto x : q) {
            ans += x.second;
        }
        cout << ans << "\n";
    };

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}