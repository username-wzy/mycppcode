#include<bits/stdc++.h>
#define ll long long

using namespace std;

struct node {
    int t, w;
    bool operator< (const node other) const {
        if (t != other.t) return t < other.t;
        return w > other.w;
    }
};

node a[505];

void solve() {
    int m, n, sum = 0;
    cin >> m >> n;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].t;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i].w;
        sum += a[i].w;
    }
    sort(a + 1, a + 1 + n);
    int sum2 = 0;
    for (int i = 1; i <= n; i++) {
        if (q.size() < a[i].t) {
            q.push(a[i].w);
        } else {
            if (q.top() < a[i].w) {
                q.pop();
                q.push(a[i].w);
            }
        }
    }
    while (!q.empty()) {
        sum2 += q.top();
        q.pop();
    }
    cout << m - (sum - sum2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // freopen("xxx.in", "r", stdin);
    // freopen("xxx.out", "w", stdout);

    int T = 1; // cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}