#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int ans = 0;
    string s, t;
    getline(cin, s);
    stringstream ss(s);
    vector<string> v;
    stack<int> stk;
    while (ss >> s) {
        if (s == "+" || s == "-") {
            ss >> t;
            if (s == "-") stk.push(-stoi(t));
            else stk.push(stoi(t));
        } else if (s == "*" || s == "/") {
            ss >> t;
            int p = stk.top(); stk.pop();
            int q = stoi(t);
            if (s == "*") stk.push(p * q);
            else stk.push(p / q);
        } else {
            stk.push(stoi(s));
        }
    }
    while (stk.size()) {
        ans += stk.top();
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