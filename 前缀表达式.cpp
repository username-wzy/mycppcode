#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    string s;
    getline(cin, s);
    vector<string> v;
    stringstream ss(s);
    while (ss >> s) {
        v.push_back(s);
    }
    stack<int> stk;
    for (int i = v.size() - 1; i >= 0; i--) {
        if(v[i] == "+") {
            int b = stk.top(); stk.pop();
            int a = stk.top(); stk.pop();
            stk.push(a + b);
        } else if (v[i] == "-") {
            int b = stk.top(); stk.pop();
            int a = stk.top(); stk.pop();
            stk.push(a - b);
        } else if (v[i] == "*") {
            int b = stk.top(); stk.pop();
            int a = stk.top(); stk.pop();
            stk.push(a * b);
        } else if (v[i] == "/") {
            int b = stk.top(); stk.pop();
            int a = stk.top(); stk.pop();
            stk.push(a / b);
        } else if (v[i] == "%") {
            int b = stk.top(); stk.pop();
            int a = stk.top(); stk.pop();
            stk.push(a % b);
        } else {
            stk.push(stoll(v[i]));
        }
    }
    cout << stk.top();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // freopen("xxx.in", "r", stdin
    // freopen("xxx.out", "w", stdout);

    int T = 1; // cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}