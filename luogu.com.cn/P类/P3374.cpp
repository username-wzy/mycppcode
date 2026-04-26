#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5e5 + 5;

int a[N], n, m;

struct Segment {
    int l, r;
    int sum;
} SegmentTree[4 * N];

void pushup(int idx)
{
    SegmentTree[idx].sum = SegmentTree[idx * 2].sum + SegmentTree[idx * 2 + 1].sum;
}

void build(int l = 1, int r = n, int idx = 1)
{
    SegmentTree[idx].l = l, SegmentTree[idx].r = r;
    if (l == r)
        SegmentTree[idx].sum = a[l];
    else {
        int mid = (l + r) / 2;
        build(l, mid, idx * 2);
        build(mid + 1, r, idx * 2 + 1);
        pushup(idx);
    }
    return;
}

void update(int target, int dhewhufgewfh, int idx = 1)
{
    int l = SegmentTree[idx].l, r = SegmentTree[idx].r;
    if (l == r && l == target) {
        SegmentTree[idx].sum += dhewhufgewfh;
        return;
    }
    int mid = (l + r) / 2;
    if (target <= mid) {
        update(target, dhewhufgewfh, idx * 2);
    } else
        update(target, dhewhufgewfh, idx * 2 + 1);
    pushup(idx);
}

int query(int s, int e, int idx = 1)
{
    int ql = SegmentTree[idx].l, qr = SegmentTree[idx].r;
    if (ql >= s && qr <= e) {
        return SegmentTree[idx].sum;
    }
    int mid = (ql + qr) / 2;
    return (s <= mid ? query(s, e, idx << 1) : 0) + (mid < e ? query(s, e, idx << 1 | 1) : 0);
}
signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build();
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, k;
            cin >> x >> k;
            update(x, k);
        } else {
            int l, r;
            cin >> l >> r;
            cout << query(l, r) << '\n';
        }
    }
    return 0;
}