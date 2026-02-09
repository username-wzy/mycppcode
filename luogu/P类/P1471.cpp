    #include <bits/stdc++.h>
    #define db double

    using namespace std;

    const int N = 1e5 + 5;

    db pf(db x) { return x * x; }
    db a[N];

    struct Segment {
        int l, r;
        db sum, sum2;
        db tag;
    } t[N << 2];

    int n, m;

    void pushup(int idx)
    {
        t[idx].sum2 = t[idx << 1].sum2 + t[idx << 1 | 1].sum2;
        t[idx].sum = t[idx << 1].sum + t[idx << 1 | 1].sum;
    }

    void build(int l = 1, int r = n, int idx = 1)
    {
        t[idx].l = l, t[idx].r = r;
        if (l == r) {
            t[idx].sum = a[l];
            t[idx].sum2 = pf(a[l]);
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
        const db tag = t[idx].tag;
        if (l == r || tag == 0)
            return;

        db& llsum = t[idx << 1].sum;
        db& lrsum = t[idx << 1].sum2;
        db& rlsum = t[idx << 1 | 1].sum;
        db& rrsum = t[idx << 1 | 1].sum2;

        const int llen = t[idx << 1].r - t[idx << 1].l + 1;
        const int rlen = t[idx << 1 | 1].r - t[idx << 1 | 1].l + 1;

        lrsum += 2 * tag * llsum + pf(tag) * llen;
        llsum += tag * llen;

        rrsum += 2 * tag * rlsum + pf(tag) * rlen;
        rlsum += tag * rlen;

        t[idx << 1].tag += tag;
        t[idx << 1 | 1].tag += tag;

        t[idx].tag = 0;
    }

    void update(int s, int e, db k, int idx = 1)
    {
        const int l = t[idx].l, r = t[idx].r;
        if (s <= l && r <= e) {
            const int len = r - l + 1;
            t[idx].sum2 += 2 * k * t[idx].sum + len * pf(k);
            t[idx].sum += len * k;
            t[idx].tag += k;
            return;
        }
        pushdown(idx);
        int mid = (l + r) >> 1;
        if (s <= mid)
            update(s, e, k, idx << 1);
        if (mid < e)
            update(s, e, k, idx << 1 | 1);
        pushup(idx);
    }

    db query1(int s, int e, int idx = 1)
    {
        const int l = t[idx].l, r = t[idx].r;
        if (s <= l && r <= e) {
            return t[idx].sum;
        }
        pushdown(idx);
        int mid = (l + r) >> 1;
        db res = 0;
        if (s <= mid)
            res += query1(s, e, idx << 1);
        if (mid < e)
            res += query1(s, e, idx << 1 | 1);
        return res;
    }

    db query2(int s, int e, int idx = 1)
    {
        const int l = t[idx].l, r = t[idx].r;
        if (s <= l && r <= e) {
            return t[idx].sum2;
        }
        pushdown(idx);
        int mid = (l + r) >> 1;
        db res = 0;
        if (s <= mid)
            res += query2(s, e, idx << 1);
        if (mid < e)
            res += query2(s, e, idx << 1 | 1);
        return res;
    }

    int main()
    {
        cin >> n >> m;
        cout << fixed << setprecision(4);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        build();
        while (m--) {
            int op;
            cin >> op;
            if (op == 1) {
                int x, y;
                double k;
                cin >> x >> y >> k;
                update(x, y, k);
            } else if (op == 2) {
                int x, y;
                cin >> x >> y;
                cout << query1(x, y) / (y - x + 1) << '\n';
            } else {
                int x, y;
                cin >> x >> y;
                int len = y - x + 1;
                db s1 = query1(x, y);
                db s2 = query2(x, y);
                cout << s2 / len - pf(s1 / len) << '\n';
            }
        }
        return 0;
    }