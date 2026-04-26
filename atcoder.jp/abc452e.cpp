#include <bits/stdc++.h>

using namespace std;
#define int long long

const int mod = 998244353;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(m + 1), prefix(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= mod; // 对a[i]取模，防止溢出
        prefix[i] = prefix[i - 1] + a[i];
        prefix[i] %= mod;
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        b[i] %= mod; // 对b[i]取模，防止溢出
    }
    int sumA = 0;
    for (int i = 1; i <= n; i++) {
        sumA += a[i] * i;
        sumA %= mod;
    }
    int sumB = 0;
    for (int i = 1; i <= m; i++) {
        sumB += b[i];
        sumB %= mod;
    }

    const int sum1 = (sumA % mod * (sumB % mod)) % mod;
    int sum2 = 0;
    for (int j = 1; j <= min(n, m); j++) { // 当i < j时 floor(i / j) == 0
        int sum = 0;
        for (int i = 1; i * j <= n; i++) {
            sum += (prefix[n] - prefix[i * j - 1] + mod) % mod;
        }
        sum %= mod; // 对sum取模，防止溢出
        sum2 += b[j] * j % mod * sum % mod; // 计算b[j] * j * sum，并累加到sum2中
        sum2 %= mod; // 对sum2取模，防止溢出
    }
    sum2 %= mod; // 对sum2取模，防止溢出
    cout << (sum1 - sum2 + mod) % mod << '\n';
    return 0;
}