#include <bits/stdc++.h>
#define ll long long

using namespace std;

constexpr int N = 1e5 + 5;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    auto solve = [] {
        int n, m;
        cin >> n >> m;
        vector<int> a(n + 1);
        unordered_map<int, int> mp;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            mp[a[i]]++;
        }
        const ll sum = accumulate(a.begin() + 1, a.end(), 0LL);
        auto mutipies_of_D = [&](int d) -> bool {
            for (auto i : mp) {
                if (i.second % d!= 0)
                    return 0;
            }
            return 1;
        };
        int cnt = 0;
        for (int k = 1; k <= m; k++) {
            int g = __gcd(n, k);
            int d = n / g;
            if (sum % d == 0 && mutipies_of_D(d)) 
                cnt++;
        }
        cout << cnt << '\n';
    };

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}