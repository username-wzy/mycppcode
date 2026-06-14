#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << '\n';
#define IAK std::ios::sync_with_stdio(false);
#define IOI std::cin.tie(nullptr)
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n + 1), b(n + 1);
    vector<ll> jc(n + 1);
    jc[0] = 1;
    jc[1] = 1;
    for (ll i = 2; i <= n; i++) {
        jc[i] = jc[i - 1] * i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    ll id1 = 0, minn = 1e9;
    for (int i = 1; i <= n; i++) {
        ll cnt = 0;
        for (int j = i + 1; j <= n; j++) {
            if (a[j] < a[i]) {
                cnt++;
            }
        }
        id1 += jc[n - i] * cnt;
    }
    ll id2 = 0;
    minn = 1e9;
    for (int i = 1; i <= n; i++) {
        ll cnt = 0;
        for (int j = i + 1; j <= n; j++) {
            if (b[j] < b[i]) {
                cnt++;
            }
        }
        id2 += jc[n - i] * cnt;
    }
    cout << abs(id1 - id2);
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