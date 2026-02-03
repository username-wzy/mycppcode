#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e6 + 10;
struct Segment {
    int l, r;
    ll sum;
} SegmentTree[N * 4]; // 线段树数组，每个节点表示一个区间，最多需要4n个节点

int a[N];
int n, maxidx = 0;

void pushup(int idx)
{
    SegmentTree[idx].sum = SegmentTree[idx << 1].sum + SegmentTree[idx << 1 | 1].sum; // 合并左右子树的信息
}

void build(int l = 1, int r = n, int idx = 1)
{ // 递归构建线段树，区间[l, r]，节点idx
    maxidx = max(maxidx, idx);
    SegmentTree[idx].l = l, SegmentTree[idx].r = r; // 节点idx表示区间[l, r]
    if (l == r) { // 叶子节点，直接赋值
        SegmentTree[idx].sum = a[l];
        return;
    }
    int mid = (l + r) >> 1; // 区间中点，将区间一分为二
    build(l, mid, idx * 2); // 递归构建左子树
    build(mid + 1, r, idx << 1 | 1); // 递归构建右子树, idx << 1 | 1 等价于 idx * 2 + 1
    pushup(idx); // 更新当前节点的信息
}

void update(int x, int y, int idx = 1)
{ // 递归更新线段树，将原数组中第x个数改为y，节点idx
    int &l = SegmentTree[idx].l, &r = SegmentTree[idx].r;
    if (l == r && l == x) {
        SegmentTree[idx].sum = y;
        return;
    }
    int mid = (l + r) >> 1; // 区间中点
    if (x <= mid) // 如果x在左子树
        update(x, y, idx << 1); // 递归更新左子树
    else
        update(x, y, idx << 1 | 1); // 递归更新右子树
    pushup(idx); // 更新当前节点的信息
}

void update2(int s, int e, int k, int idx = 1)
{
    int l = SegmentTree[idx].l, r = SegmentTree[idx].r;
    if (l == r) {
        if (s <= l && l <= e) {
            SegmentTree[idx].sum += k;
        }
        return;
    }
    update2(s, e, k, idx << 1);
    update2(s, e, k, idx << 2 | 1);
}

ll query(int l, int r, int idx = 1)
{ // 递归查询线段树，查询区间[l, r]的和，节点idx
    int &ql = SegmentTree[idx].l, &qr = SegmentTree[idx].r;
    if (ql >= l && qr <= r) {
        return SegmentTree[idx].sum; // 当前节点区间完全包含查询区间，直接返回节点信息
    }
    int mid = (ql + qr) >> 1;
    return (l <= mid ? query(l, r, idx << 1) : 0) + (mid < r ? query(l, r, idx << 1 | 1) : 0); // 如果mid > l, 则查询左子树; 如果mid < r, 则查询右子树，合并结果
}

void printSegmentTree()
{
    for (int i = 1; i <= maxidx; ++i) {
        cerr << i << ": " << SegmentTree[i].l << " " << SegmentTree[i].r << " " << SegmentTree[i].sum << '\n';
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    build(); // 构建线段树
    printSegmentTree();

    // 将原数组中第x个数改为y，单点修改
    int x, y;
    cin >> x >> y;
    update(x, y);
    cerr << "after update:" << '\n';
    printSegmentTree();

    // 查询区间[l, r]的和
    int l, r;
    cin >> l >> r;
    cout << query(l, r) << '\n';

    //
    return 0;
}