#include<bits/stdc++.h>
#define ll long long

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

void solve() {
    int L, n;
    cin >> L >> n;
    vector<pair<int, int> > a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin() + 1, a.end(), cmp);
    int end = a[1].second, ans = 0, begin = a[1].first;
    for (int i = 2; i <= n; i++) {
        if (a[i].first <= end) {
            end = max(end, a[i].second);
        } else {
            ans = end - begin + 1;
            begin = a[i].first;
            end = a[i].second;
        }
    }
    ans += end - begin + 1;
    cout << L + 1 - ans;
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