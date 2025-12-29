#include<bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int n; 
    cin >> n;
    vector<pair<int, int>> a;
    priority_queue<int> pq;
    for (int i = 1; i <= n; i++) {
        int t1, t2; cin >> t1 >> t2; 
        a.push_back({t2, t1});
    }
    int sum = 0;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        if (sum + a[i].second < a[i].first) {
            pq.push(a[i].second);
            sum += a[i].second;
        } else if (a[i].second <= pq.top()) {
            sum -= pq.top();
            pq.pop();
            sum += a[i].second;
            pq.push(a[i].second);
        }
    }
    cout << pq.size();
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