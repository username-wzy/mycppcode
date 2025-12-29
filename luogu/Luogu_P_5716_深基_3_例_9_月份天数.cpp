#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int y, m;
    cin >> y >> m;
    bool runnian = (y % 4 == 0 && y % 100 != 0 || y % 400 == 0);
    if (runnian && m == 2) {cout << 29; return ;}
    if (m == 2) {
        cout << 28;
        return ;
    }
    set<int> st = {1, 3, 5, 7, 8, 10, 12};
    if (st.find(m) == st.end()) {
        cout << 30;
    } else cout << 31;
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