#include <bits/stdc++.h>
#define debug(...) cerr << #__VA_ARGS__ << " = " << __VA_ARGS__ << endl;
#define IAK std::ios::sync_with_stdio(false);
#define IOI std::cin.tie(nullptr)
#define elif else if
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<long, long>;

int mod = 1e9;

ll quick_pow(ll base, ll exp)
{
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            res = (res * base) % mod; // 如果指数为奇数
        base = (base * base) % mod; // 底数平方
        exp /= 2; // 指数除以2
    }
    return res;
}

void solve()
{
    ll n;
    cin >> n;
    if (n < 3)
        cout << n;
    elif (n % 3 == 0) cout << quick_pow(3, n / 3);
    elif (n % 3 == 1) cout << quick_pow(3, n / 3 - 1) * 4 % mod;
    else cout << quick_pow(3, n / 3) * 2 % mod;
    cout << '\n';
}

int main()
{
    IAK IOI;
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}