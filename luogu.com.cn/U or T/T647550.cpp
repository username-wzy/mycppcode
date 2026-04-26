#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, a;
ll d;
vector<ll> b;

vector<ll> dplb;
ll lb(int a)
{
    if (a < 0 || b[a] == 0) {
        return 0;
    }
    if (dplb[a] != -1) {
        return dplb[a];
    }
    if (b[a] == 1) {
        ll ans = lb(a - 1) + 1;
        dplb[a] = ans;
        return ans;
    }
    ll p3 = 0;
    if (a > 2 && b[a - 1] == 1 && b[a - 2] == 1) {
        p3 = lb(a - 3);
    }
    ll p1 = lb(a - 1);
    ll p2 = lb(a - 2);
    ll ans = max({ p1, p2, p3 }) + b[a];
    dplb[a] = ans;
    return ans;
}

vector<ll> dprb;
ll rb(int a)
{
    if (a >= n || b[a] == 0) {
        return 0;
    }
    if (dprb[a] != -1) {
        return dprb[a];
    }
    if (b[a] == 1) {
        ll ans = rb(a + 1);
        dprb[a] = ans;
        return ans;
    }
    ll p3 = 0;
    if (a + 2 < n && b[a + 1] == 1 && b[a + 2] == 1) {
        p3 = rb(a + 3);
    }
    ll p1 = rb(a + 1);
    ll p2 = rb(a + 2);
    ll ans = max({ p1, p2, p3 }) + b[a];
    dprb[a] = ans;
    return ans;
}

vector<ll> dpl;
ll l(int a)
{
    if (a < 0 || b[a] == 0) {
        return 0;
    }
    if (dpl[a] != -1) {
        return dpl[a];
    }
    ll ans = max(l(a - 1), l(a - 2)) + b[a];
    dpl[a] = ans;
    return ans;
}

vector<ll> dpr;
ll r(int a)
{
    if (a >= n || b[a] == 0) {
        return 0;
    }
    if (dpr[a] != -1) {
        return dpr[a];
    }
    ll ans = max(r(a + 1), r(a + 2)) + b[a];
    dpr[a] = ans;
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> a >> d;
    d += d;
    n--, a--;
    b.resize(n);

    for (ll& i : b) {
        cin >> i;
        i = (i - 2) / d;
    }

    ll ans = 0;
    dplb.resize(n, -1);
    dprb.resize(n, -1);
    dpl.resize(n, -1);
    dpr.resize(n, -1);
    for (int i = -2; i <= 2; i++) {
        if (0 <= a + i && a + i < n) {
            ll p1 = lb(a + i) + r(a + i + 1);
            ll p2 = rb(a + i) + l(a + i - 1);
            ans = max(ans, max(p1, p2));
        }
    }
    cout << ans;
    return 0;
}
