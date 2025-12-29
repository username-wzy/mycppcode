#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, cnt = 0;
    cin >> n;
    vector<pair<int, pair<int, int>>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second.first >> v[i].second.second;
    }
    for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) {
        if (abs(v[i].first - v[j].first) <= 5 && 
            abs(v[i].second.first - v[j].second.first) <= 5 && 
            abs(v[i].second.second - v[j].second.second) <= 5 && 
            abs(v[i].first + v[i].second.first + v[i].second.second - 
                (v[j].first + v[j].second.first + v[j].second.second))
                    <= 10) {
            cnt++;
        }
    }
    cout << cnt;
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