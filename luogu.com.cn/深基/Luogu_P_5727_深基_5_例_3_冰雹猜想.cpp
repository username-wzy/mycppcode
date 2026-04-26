#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    vector<int> a;
    int n;
    cin >> n;
    while (n > 1) {
        a.push_back(n);
        if (n % 2) n = n * 3 + 1;
        else n /= 2;
    }
    a.push_back(1);
    for (int i = a.size() - 1; i >= 0; i--) {
        cout << a[i] << ' ';
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