#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    string s, target, t;
    getline(cin, target);
    getline(cin, s);
    for (auto &p : target) {
        if (isupper(p)) {
            p = tolower(p);
        }
    }
    for (auto &p : s) {
        if (isupper(p)) {
            p = tolower(p);
        }
    }
    int cnt = 0;
    stringstream ss(s), tt(s);
    while (ss >> t) {
        if (t == target) {
            cnt++;
        }
    }
    if (cnt == 0) cout << -1;
    else {
        cout << cnt << " ";
        int i = 0;
        while (tt >> t) {
            if (t == target) {
                int k = s.find(t);
                cout << k;
                return ;
            }
            i++;
        }
    }
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