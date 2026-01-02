#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    string s;
    cin >> s;
    stack<int> stk;
    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) stk.push(s[i] - '0');
        if (s[i] == '&') {
            bool x = stk.top() - '0';
            stk.pop();
            bool y = s[++i] - '0';
            stk.push(x && y);
        }
    }
    bool ans = 0;
    while (stk.size()) {
        if (stk.top()) ans = 1;
        stk.pop();
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