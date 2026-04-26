#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e17;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];

    vector<ll> s1(n + 1), s2(n + 1);
    for (int i = 1; i <= n; i++) {
        s1[i] = s1[i - 1] + a[i];
        s2[i] = s2[i - 1] + b[i];
    }

    vector<ll> rightMax(n + 2, -INF); // 从i到n的后缀最大值
    for (int i = n; i >= 0; i--)
        rightMax[i] = max(rightMax[i + 1], s2[i]);

    vector<ll> leftMin(n + 1, INF); // 从1到i的前缀最小值
    leftMin[0] = s2[0];
    for (int i = 1; i <= n; i++)
        leftMin[i] = min(leftMin[i - 1], s2[i]);

    ll ans = -INF;
    // 初始化第一个合法 B

    ll bestB = s1[1];
    for (int r = 2; r <= n - 1; r++) {
        ll A = s1[r] + rightMax[r + 1];
        ans = max(ans, A - bestB);

        ll B = s1[r] + leftMin[r - 1];
        bestB = min(bestB, B);
    }

    cout <<ans << "\n";
}
