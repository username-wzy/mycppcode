#include<bits/stdc++.h>
#define ll long long

using namespace std;

string div(const string& a, ll b) {
    string res = "";
    ll r = 0;
    
    for (size_t i = 0; i < a.size(); i++) {
        ll x = a[i] - '0';
        ll temp = r * 10 + x;
        res += (temp / b) + '0';
        r = temp % b;
    }
    ll pos = -1;
    for (size_t i = 0; i < res.size(); i++) {
        if (res[i] != '0') {
            pos = i;
            break;
        }
    }
    if (pos == -1) return "0";
    else return res.substr(pos);
}


void solve() {
    string n;
    ll k;
    cin >> n >> k;
    cout << div(n, k - 1);
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