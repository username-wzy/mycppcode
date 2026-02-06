#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
constexpr int N = 1e5 + 5;

struct Segment {
    int l, r;
    ll sum, add_tag, mult_tag;
} t[N << 4];

int n, mod, a[N];

void pushup(int idx)
{
    t[idx].sum = (t[idx << 1].sum + t[idx << 1 | 1].sum) % mod;
}

void build(int l = 1, int r = n, int idx = 1)
{
    t[idx].l = l, t[idx].r = r;
    t[idx].sum = t[idx].add_tag = 0;
    t[idx].mult_tag = 1;
    if (l == r) {
        t[idx].sum = a[l] % mod;
        return;
    }
    const int mid = (l + r) >> 1;
    build(l, mid, idx << 1);
    build(mid + 1, r, idx << 1 | 1);
    pushup(idx);
}

void pushdown(int idx)
{
    const int l = t[idx].l, r = t[idx].r;
    const ll mult_tag = t[idx].mult_tag, add_tag = t[idx].add_tag;
    if (l == r)
        return;

    const int left_l = t[idx << 1].l,
              right_l = t[idx << 1].r;
    ll& left_sum = t[idx << 1].sum;
    left_sum *= mult_tag,
                                                    left_sum %= mod;
    left_sum += (right_l - left_l + 1) * add_tag,
                                                    left_sum %= mod;
    ll &left_mult_tag = t[idx << 1].mult_tag,
       &left_add_tag = t[idx << 1].add_tag;
    left_mult_tag *= mult_tag,
                                                    left_mult_tag %= mod;
    left_add_tag = left_add_tag * mult_tag + add_tag,
                                                    left_add_tag %= mod;

    const int left_r = t[idx << 1 | 1].l,
              right_r = t[idx << 1 | 1].r;
    ll& right_sum = t[idx << 1 | 1].sum;
    right_sum *= mult_tag,
                                                    right_sum %= mod;
    right_sum += (right_r - left_r + 1) * add_tag,
                                                    right_sum %= mod;
    ll &right_mult_tag = t[idx << 1 | 1].mult_tag,
       &right_add_tag = t[idx << 1 | 1].add_tag;
    right_mult_tag *= mult_tag,
                                                    right_mult_tag %= mod;
    right_add_tag = right_add_tag * mult_tag + add_tag,
                                                    right_add_tag %= mod;

    t[idx].add_tag = 0, t[idx].mult_tag = 1;
}

void update_add(int s, int e, ll k, int idx = 1)
{
    const int l = t[idx].l, r = t[idx].r;
    if (s <= l && r <= e) {
        int len = r - l + 1;
        t[idx].sum += (ll)len * k % mod;
            t[idx].sum %= mod;
        t[idx].add_tag += k;
            t[idx].add_tag %= mod;
        return;
    }
    pushdown(idx);
    const int mid = (l + r) >> 1;
    if (s <= mid)
        update_add(s, e, k, idx << 1);
    if (mid < e)
        update_add(s, e, k, idx << 1 | 1);
    pushup(idx);
}

void update_mult(int s, int e, ll k, int idx = 1)
{
    const int l = t[idx].l, r = t[idx].r;
    if (s <= l && r <= e) {
        t[idx].sum *= k,
            t[idx].sum %= mod;
        t[idx].add_tag *= k,
            t[idx].add_tag %= mod;
        t[idx].mult_tag *= k,
            t[idx].mult_tag %= mod;
        return;
    }
    pushdown(idx);
    const int mid = (l + r) >> 1;
    if (s <= mid)
        update_mult(s, e, k, idx << 1);
    if (mid < e)
        update_mult(s, e, k, idx << 1 | 1);
    pushup(idx);
}

ll query(int s, int e, int idx = 1) {
    const int l = t[idx].l, r = t[idx].r;
    if (s <= l && r <= e)
        return t[idx].sum % mod;
    if (s > r || e < l)
        return 0;
    pushdown(idx);
    return (query(s, e, idx << 1) + query(s, e, idx << 1 | 1)) % mod;
}

signed main()
{
    int q;
    cin >> n >> q >> mod;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build();
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, y, k;
            cin >> x >> y >> k;
            update_mult(x, y, k);
        } else if (op == 2) {
            int x, y, k;
            cin >> x >> y >> k;
            update_add(x, y, k);

        } else {
            int x, y;
            cin >> x >> y;
            cout << query(x, y) % mod << '\n';
        }
    }
    return 0;
}       