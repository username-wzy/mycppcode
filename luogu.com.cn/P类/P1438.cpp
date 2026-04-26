#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5 + 10;
struct Segment {
    int l, r;
    int sum, lazytag;
} SegmentTree[N * 4];
int a[N], n;

void pushup(int idx)
{
    SegmentTree[idx].sum = SegmentTree[idx << 1].sum + SegmentTree[idx << 1 | 1].sum;
}

void pushdown(int idx)
{
    int l = SegmentTree[idx].l, r = SegmentTree[idx].r;
    if (l == r || SegmentTree[idx].lazytag == 0)
        return;
    int tag = SegmentTree[idx].lazytag;
    SegmentTree[idx << 1].sum += (SegmentTree[idx << 1].r - SegmentTree[idx << 1].l + 1) * tag;
    SegmentTree[idx << 1 | 1].sum += (SegmentTree[idx << 1 | 1].r - SegmentTree[idx << 1 | 1].l + 1) * tag;
    SegmentTree[idx << 1].lazytag += tag;
    SegmentTree[idx << 1 | 1].lazytag += tag;
    SegmentTree[idx].lazytag = 0;
}

void build(int l = 1, int r = n, int idx = 1)
{
    SegmentTree[idx].l = l, SegmentTree[idx].r = r;
    if (l == r) {
        SegmentTree[idx].sum = a[l];
        return;
    }
    int mid = ((l + r)) >> 1;
    build(l, mid, idx * 2);
    build(mid + 1, r, idx << 1 | 1);
    pushup(idx);
}

void update(int s, int e, int k, int idx = 1)
{
    int l = SegmentTree[idx].l, r = SegmentTree[idx].r;
    if (s <= l && r <= e) {
        int len = r - l + 1;
        SegmentTree[idx].sum += len * k;
        SegmentTree[idx].lazytag += k;
        return;
    }
    pushdown(idx);
    int mid = (l + r) >> 1;
    if (mid >= s)
        update(s, e, k, idx << 1);
    if (mid < e)
        update(s, e, k, idx << 1 | 1);
    pushup(idx);
}

int query(int s, int e, int idx = 1)
{
    int l = SegmentTree[idx].l, r = SegmentTree[idx].r;
    if (s <= l && r <= e)
        return SegmentTree[idx].sum;
    pushdown(idx);
    int mid = (l + r) / 2;
    int res = 0;
    if (mid >= s)
        res += query(s, e, idx << 1);
    if (mid < e)
        res += query(s, e, idx << 1 | 1);
    return res;
}
signed main()
{
    int m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = n; i >= 1; i--){
        a[i] -= a[i - 1];
    }
        build();
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r, k, d;
            cin >> l >> r >> k >> d;
            update(l, l, k);
            if (l + 1 <= r)
                update((long long)l + 1, r, d);
            if (r + 1 <= n)
                update((long long)r + 1, (long long)r + 1, (long long)-((r - l) * d + k));
        } else {
            int x;
            cin >> x;
            cout << query((long long)1, x) << '\n';
        }
    }
    return 0;
}