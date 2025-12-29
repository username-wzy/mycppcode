#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int x;
    cin >> x;
    bool a = (x % 2 == 0), b = (x > 4 && x <= 12);
    if (a && b) 
        cout << "1 ";
    else
        cout << "0 ";
    if (a || b)
        cout << "1 ";
    else
        cout << "0 ";
    if (a && !b || !a && b) 
        cout << "1 ";
    else
        cout << "0 ";
    if (!a && !b) 
        cout << "1";
    else 
        cout << "0";
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