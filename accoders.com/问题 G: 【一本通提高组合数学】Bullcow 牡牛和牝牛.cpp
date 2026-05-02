#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int p = 5000011;

/*
    分析，需要x个A，y个B, x + y <= n， y = (x - 1)k
    所以要求的是x+(x-1)k <= n
    x + xk - k <= n
    x(1 + k) - k <= n
    x(1 + k) <= n + k
    x <= (n + k) / (1 + k)
    因此枚举从1到x <= (n + k) / (1 + k)的整数
    以后x + (x - 1)k指的是所有x计算的结果,用[x + (x - 1)k]表示
    确定取值范围后计算所有必须要的数量x + (x - 1)k
    留给我们自由分配的就只剩n - [(x + (x - 1)k)]
    我们可一分配的位置有[x + 1]个位置（两端即2，加上中间x - 1即x + 1）
    利用隔板法把n - [(x + (x - 1)k)]个元素放到[x + 1]个位置中,我们设m为n-[(x + (x - 1)k)] 即
    C_{m + (x+1) - 1} ^ {(x+1) - 1} = C_{m + x}^{x}
    枚举所有x，求和即可
*/

ll qpow(ll a, ll b, ll p)
{
    ll res = 1;
    while (b) {
        if (b & 1)
            res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

ll C(ll n, ll m)
{
    if (m > n)
        return 0;
    if (n - m < m)
        m = n - m;
    ll up = 1;
    ll down = 1;
    for (int i = 1; i <= m; i++) {
        up = up * (n - i + 1) % p;
        down = down * i % p;
    }
    return up * qpow(down, p - 2, p) % p;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k;
    cin >> n >> k;

    ll ans = 0;
    for (int x = 0; x <= (n + k) / (1 + k); x++) { // 允许x为0，也就是0个A的情况
        ll m = n - (x + (x - 1) * k);
        ans += C(m + x, x) % p;
    }

    cout << ans % p;
}