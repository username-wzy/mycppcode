#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, m;
long long a[N];
long long sum[500], tag[500];
int bel[N], L[500], R[500], blk_cnt;
int B; // 块大小

// 建块
void build()
{
    B = sqrt(n);
    blk_cnt = (n + B - 1) / B;
    for (int i = 1; i <= blk_cnt; i++) {
        L[i] = (i - 1) * B + 1;
        R[i] = min(i * B, n);
        for (int j = L[i]; j <= R[i]; j++)
            bel[j] = i, sum[i] += a[j];
    }
}

// 区间加
void range_add(int l, int r, long long k)
{
    int bl = bel[l], br = bel[r];
    if (bl == br) {
        for (int i = l; i <= r; i++)
            a[i] += k, sum[bl] += k;
        return;
    }
    // 左边零散
    for (int i = l; i <= R[bl]; i++)
        a[i] += k, sum[bl] += k;
    // 中间整块
    for (int b = bl + 1; b <= br - 1; b++)
        tag[b] += k;
    // 右边零散
    for (int i = L[br]; i <= r; i++)
        a[i] += k, sum[br] += k;
}

// 区间求和
long long range_sum(int l, int r)
{
    long long res = 0;
    int bl = bel[l], br = bel[r];
    if (bl == br) {
        for (int i = l; i <= r; i++)
            res += a[i] + tag[bl];
        return res;
    }
    // 左边零散
    for (int i = l; i <= R[bl]; i++)
        res += a[i] + tag[bl];
    // 中间整块
    for (int b = bl + 1; b <= br - 1; b++)
        res += sum[b] + tag[b] * (R[b] - L[b] + 1);
    // 右边零散
    for (int i = L[br]; i <= r; i++)
        res += a[i] + tag[br];
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    build();

    while (m--) {
        string op;
        int l, r;
        cin >> op >> l >> r;
        if (op == "add") {
            long long k;
            cin >> k;
            range_add(l, r, k);
        } else { // sum
            cout << range_sum(l, r) << '\n';
        }
    }
    return 0;
}
