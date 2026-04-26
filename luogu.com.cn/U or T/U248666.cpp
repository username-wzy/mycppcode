#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e5 + 5;

struct Interval {
    int a, b;
} intervals[N];

bool cmp(Interval a, Interval b) {
    return a.b < b.b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> intervals[i].a >> intervals[i].b;
    }
    sort(intervals + 1, intervals + 1 + n, cmp);
    int maxright = intervals[1].b, cnt = 1;
    for (int i = 2; i <= n; i++) {
        if (intervals[i].a > maxright) {
            cnt++;
            maxright = intervals[i].b;
        }
    }
    cout << cnt;
    return 0;
}