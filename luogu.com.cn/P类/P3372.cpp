#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5 + 10;
struct Segment {
    int l, r;
    int sum, lazytag;
} SegmentTree[N * 4]; // 线段树数组，每个节点表示一个区间，最多需要4n个节点

int a[N], n;

void pushup(int idx)
{
    SegmentTree[idx].sum = SegmentTree[idx << 1].sum + SegmentTree[idx << 1 | 1].sum; // 合并左右子树的信息
}

void pushdown(int idx)
{
    int l = SegmentTree[idx].l, r = SegmentTree[idx].r;
    if (l == r || SegmentTree[idx].lazytag == 0) // 没有子节点或者没有懒标记
        return;
    /*
        1. 将左右儿子更新
        2. 更新当前节点的懒标记
        3. 清空当前节点的懒标记
    */
    int tag = SegmentTree[idx].lazytag;
    SegmentTree[idx << 1].sum += (SegmentTree[idx << 1].r - SegmentTree[idx << 1].l + 1) * tag; // 左子树的区间和也加上tag * 区间长度
    SegmentTree[idx << 1 | 1].sum += (SegmentTree[idx << 1 | 1].r - SegmentTree[idx << 1 | 1].l + 1) * tag; // 右子树的区间和也加上tag * 区间长度
    SegmentTree[idx << 1].lazytag += tag; // 左子树的懒标记也加上tag
    SegmentTree[idx << 1 | 1].lazytag += tag; // 右子树的懒标记也加上tag
    SegmentTree[idx].lazytag = 0; // 清空当前节点的懒标记
}

void build(int l = 1, int r = n, int idx = 1)
{ // 递归构建线段树，区间[l, r]，节点idx
    SegmentTree[idx].l = l, SegmentTree[idx].r = r; // 节点idx表示区间[l, r]
    if (l == r) { // 叶子节点，直接赋值
        SegmentTree[idx].sum = a[l];
        return;
    }
    int mid = ((l + r)) >> 1; // 区间中点，将区间一分为二
    build(l, mid, idx * 2); // 递归构建左子树
    build(mid + 1, r, idx << 1 | 1); // 递归构建右子树, idx << 1 | 1 等价于 idx * 2 + 1
    pushup(idx); // 更新当前节点的信息
}

void update(int& s, int& e, int& k, int idx = 1)
{
    int l = SegmentTree[idx].l, r = SegmentTree[idx].r;
    if (s <= l && r <= e) {
        int len = r - l + 1; // 植树问题
        SegmentTree[idx].sum += len * k; // 区间[l, r]每个元素都加上k，所以区间和增加了len * k
        SegmentTree[idx].lazytag += k; // 因为是+=不是=，因为可能有多次更新
        return;
    }
    pushdown(idx); // 下传懒标记
    int mid = (l + r) >> 1;
    if (mid >= s) // 左子树有交集
        update(s, e, k, idx << 1); // 递归更新左子树
    if (mid < e) // 右子树有交集
        update(s, e, k, idx << 1 | 1); // 递归更新右子树
    pushup(idx); // 更新当前节点的信息
}

int query(int s, int e, int idx = 1)
{
    int l = SegmentTree[idx].l, r = SegmentTree[idx].r;
    if (s <= l && r <= e) // 完全包含
        return SegmentTree[idx].sum; // 返回当前节点的区间和
    pushdown(idx); // 下传懒标记
    int mid = (l + r) >> 1;
    int res = 0;
    if (mid >= s) // 左子树有交集
        res += query(s, e, idx << 1); // 递归查询左子树
    if (mid < e) // 右子树有交集
        res += query(s, e, idx << 1 | 1); // 递归查询右子树
    return res; // 返回查询结果
}

signed main()
{
    int m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    build(); // 构建线段树
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, y, k;
            cin >> x >> y >> k;
            update(x, y, k);
        } else {
            int x, y;
            cin >> x >> y;
            cout << query(x, y) << '\n';
        }
    }
    return 0;
}