#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v, a;
    vector<pair<int, int>> ord; 
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        ord.push_back({a, b});
    }
    sort(ord.begin(), ord.end());
    for (auto [x, y] : ord) {
        if (y - x >= 0) a.push_back(y - x);
    }
    for (auto i : a) {
        auto it = upper_bound(v.begin(), v.end(), i);
        if (it == v.end()) {
            v.push_back(i); 
        } else *it = i;
    }
    cout << v.size();
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