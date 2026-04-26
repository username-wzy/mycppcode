#include<bits/stdc++.h>
#define ll long long

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i].first >> v[i].second;
    sort(v.begin() + 1, v.end(), cmp);
    int last = v[1].second, ans = 1;
    for (int i = 2; i <= n; i++) {
        if (v[i].first >= last) {
            ans++;
            last = v[i].second;
        }
    }
    cout << ans;
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