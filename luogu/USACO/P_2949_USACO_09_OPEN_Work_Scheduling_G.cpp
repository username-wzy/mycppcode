#include<bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int n; 
    cin >> n;
    vector<pair<int, int>> a;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; i++) {
        int di, pi; cin >> di >> pi; 
        a.push_back({di, pi});
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        if (a[i].first > pq.size()) pq.push(a[i].second);
        else { //反悔 bro
            if (a[i].second > pq.top()) {
                pq.pop();
                pq.push(a[i].second);
            }
        }
    }
    int ans = 0;
    while (!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }
    cout << ans;
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