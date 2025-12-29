#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> coins(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> coins[i].first >> coins[i].second;
    }
    sort(coins.begin(), coins.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    });
    for (int i = 1;  i <= n; i++) {
        if (abs(coins[i].first - coins[i - 1].first) > abs(coins[i].second - coins[i - 1].second)) {
            cout << "Notabletocatch\n";
            return ;
        }
    }

    cout << "Abletocatch\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // freopen("xxx.in", "r", stdin);
    // freopen("xxx.out", "w", stdout);

    int T = 1; cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}