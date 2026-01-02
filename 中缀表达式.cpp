#include<bits/stdc++.h>
#define ll long long

using namespace std;

unordered_map<string, int> idx = { {"+", 1},{"-", 1},{"*", 2},{"/", 2},{"%", 2},{"^", 3},{"(", 0} };

bool isopr(string &s) {
    return (s == "+" || s == "-" || s == "*" || s == "/" || s == "%" || s == "^");
}

string split(string s) {
    string t;
    bool flag = 1;
    for (auto i : s) {
        if(i == '-' && flag) {
            t.push_back(i);
            flag = 0;
        } else if (i == '+' || i == '-' || i == '/' || i == '*' || i == '(' || i == ')' || i == '^' || i == '%') {
            t.push_back(' ');
            t.push_back(i);
            t.push_back(' ');
            flag = i != ')';
        } else {
            t.push_back(i);
            flag = 0;
        }
    }
    return t;
}

int calc(vector<string> &v) {
    stack<int> stk;
    for (auto s : v) {
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
            stk.push(stoi(s));
        }
    }
    return stk.top();
}

void solve() {
    string s;
    cin >> s;
    string t = split(s);
    cerr << t << '\n';
    stringstream ss(t);
    stack<string> stk;
    vector<string> ans;
    while (ss >> s) {
        if (s == "(") stk.push(s);
        else if (isopr(s)) {
            while (!stk.empty() && idx[stk.top()] >= idx[s]) {
                ans.push_back(stk.top()); stk.pop();
            }
            stk.push(s);
        } else if(s == ")") {
            while (stk.top() != "(") {
                ans.push_back(stk.top()); stk.pop();
            }
            stk.pop();
        } else ans.push_back(s);
    }
    while (stk.size()) {
        ans.push_back(stk.top()); stk.pop();
    }
    // for (auto i : ans) cout << i << " ";
    cout << calc(ans);
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