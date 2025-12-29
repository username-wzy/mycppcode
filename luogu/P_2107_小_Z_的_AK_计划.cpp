#include<bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin() + 1, a.end());
    int sum = 0;
    priority_queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (q.empty()) {
            if (a[i].first + a[i].second <= m) {
                q.push(a[i].second);
            }
        } else {
            if (sum + a[i].first + a[i].second <= m) {
                q.push(a[i].second);
                sum += a[i].second;
            } else if (sum + q.top() + a[i].first + a[i].second <= m) {
                sum -= q.top();
                q.pop();
                sum += a[i].second;
                q.push(a[i].second);
            }
        }
    }
    cout << q.size();
}

signed main() {
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