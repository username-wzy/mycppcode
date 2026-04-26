#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

/*
    从m朵花，n个箱子中，每个箱子可以放任意朵花，总和=m，很明显是隔板法，即 C ( m + n - 1, n - 1)
        But, 有上限f[i]，即每个箱子最多放f[i]朵花
        So, 我们考虑正难则反，即考虑所有超限的情况，
            枚举每一个箱子是否会超限即箱子i放f[i]+1朵花
            用总和m - 超限情况的数量
            让后再使用隔板法计算
            Butt, 我们注意到可能会减去重复的:
                所以通过容斥原理将所有超限情况多减了的情况加回来
    因为模的原因，C ( m + n - 1, n - 1) 不能直接计算，需要使用模逆元

*/

const int MOD = 1e9 + 7;
ll inv[25]; // i在mod MOD意义下的“倒数” 也就是模逆元

ll qpow(ll a, ll b)
{
    ll res = 1;
    while (b) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }

    return res;
}
void init()
{
    for (int i = 1; i <= 20; i++)
        inv[i] = qpow(i, MOD - 2);
}

ll cnk(ll n, int k)
{
    if (n < k)
        return 0;
    ll res = 1;
    for (int i = 0; i < k; i++) {
        res = res * (n - i) % MOD;
        res = res * inv[i + 1] % MOD;
    }
    return res;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> f(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> f[i];
    }
    ll ans = 0;
    init();
    for (int cxqk = 0; cxqk < (1 << n); cxqk++) {
        ll sum = 0; // 超了的数量
        ll boxes = 0; // 超了的箱子数量
        for (int i = 1; i <= n; i++) {
            if (cxqk & (1 << (i - 1))) { // 箱子i会超限
                sum += f[i] + 1;
                boxes++;
            }
        }
        ll res = m - sum;
        ll C = cnk(res + n - 1, n - 1);
        if (boxes & 1)
            ans = (ans - C + MOD) % MOD;
        else
            ans = (ans + C) % MOD;
    }
    cout << ans;
    return 0;
}