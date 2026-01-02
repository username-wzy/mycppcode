#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    string s;
    stack<ll> stk;
    while (cin >> s) {
        if(s == "+") {
            int b = stk.top(); stk.pop();
            int a = stk.top(); stk.pop();
            stk.push(a + b);
        } else if (s == "-") {
            int b = stk.top(); stk.pop();
            int a = stk.top(); stk.pop();
            stk.push(a - b);
        } else if (s == "*") {
            int b = stk.top(); stk.pop();
            int a = stk.top(); stk.pop();
            stk.push(a * b);
        } else if (s == "/") {
            int b = stk.top(); stk.pop();
            int a = stk.top(); stk.pop();
            stk.push(a / b);
        } else if (s == "%") {
            int b = stk.top(); stk.pop();
            int a = stk.top(); stk.pop();
            stk.push(a % b);
        } else {
            stk.push(stoll(s));
        }
    }
    cout << stk.top();
    stk.pop();
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