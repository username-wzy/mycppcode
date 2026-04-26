#include<bits/stdc++.h>
#define ll long long

using namespace std;

struct cow {
    ll t, d;
    bool operator< (const cow other) const {
        return t * other.d < other.t * d;
    }
}cows[100005];


void solve() {
    ll n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> cows[i].t >> cows[i].d;
    }
    sort(cows + 1, cows + 1 + n);
    ll time = 0, sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += time * cows[i].d;
        time += 2 * cows[i].t;
    }
    cout << sum;
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