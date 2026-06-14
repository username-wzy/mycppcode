#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << '\n';
#define IAK std::ios::sync_with_stdio(false);
#define IOI std::cin.tie(nullptr)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<long, long>;

constexpr int inf = 1e9 + 5;

void solve()
{
    /*
                0 < xj < xi
                0 < yj < yi
                先满足 0 < xj < xi
    */
    int n;
    cin >> n;
    vector<pii> a;
    a.reserve(n);
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        a.emplace_back(x, y);
    }
    ranges::sort(a);
    int min_y = inf; // 前面最小的y
    int ans = 0;
    for (int i = 0; i < static_cast<int>(a.size()); i++) {
        const auto [x, y] = a[i];
        if (min_y > y) // 因为第一个条件满足，且前面最小的y都比你大，条件二不满足后就绝对不可以
            ans++;
        // 否则 第二个条件满足就绝对可以
        min_y = min(min_y, y);
    }
    cout << ans << '\n';
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