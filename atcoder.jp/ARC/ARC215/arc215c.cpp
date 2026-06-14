#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * Segment Tree to maintain the maximum Z value seen so far for a given Y coordinate.
 * This allows us to check if any point already processed (which has a larger X)
 * also has a larger Y and a larger Z.
 */
struct SegmentTree {
    int n;
    vector<int> tree;
    SegmentTree(int n)
        : n(n)
        , tree(4 * n + 1, 0)
    {
    }

    void update(int node, int start, int end, int idx, int val)
    {
        if (start == end) {
            tree[node] = max(tree[node], val);
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid)
            update(2 * node, start, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, end, idx, val);
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    int query(int node, int start, int end, int l, int r)
    {
        if (r < start || end < l)
            return 0;
        if (l <= start && end <= r)
            return tree[node];
        int mid = (start + end) / 2;
        return max(query(2 * node, start, mid, l, r),
            query(2 * node + 1, mid + 1, end, l, r));
    }
};

struct Point {
    int x, y, z, id;
};

void solve()
{
    int N;
    cin >> N;
    vector<Point> p(N);
    int maxY = 0;
    for (int i = 0; i < N; i++) {
        cin >> p[i].x >> p[i].y >> p[i].z;
        p[i].id = i;
        maxY = max(maxY, p[i].y);
    }

    // Sort by X descending.
    // If X is tied, it doesn't matter because strict dominance requires X1 > X2.
    sort(p.begin(), p.end(), [](const Point& a, const Point& b) {
        return a.x > b.x;
    });
    SegmentTree st(N);
    int survivors = 0;

    // To handle strict dominance (X1 > X2), we process points with the same X in batches.
    int i = 0;
    while (i < N) {
        int j = i;
        // Find all points with the same X
        while (j < N && p[j].x == p[i].x)
            j++;

        for (int k = i; k < j; k++) {
            // Check if there is any point already in the tree (which has a strictly larger X)
            // that has a strictly larger Y and strictly larger Z.
            int maxZ = st.query(1, 1, N, p[k].y + 1, N);
            if (maxZ <= p[k].z) {
                survivors++;
            }
        }

        // After checking the whole batch, add them to the Segment Tree
        for (int k = i; k < j; k++) {
            st.update(1, 1, N, p[k].y, p[k].z);
        }
        i = j;
    }

    cout << survivors << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}