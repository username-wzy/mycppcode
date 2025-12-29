#include<bits/stdc++.h>
#define int long long
#define fir first
#define sec second

using namespace std;

pair<int, int> a[100005], b[1000005];

bool cmp(pair<int, int> a, pair<int, int> b) {
    return abs(a.fir - a.sec) > abs(b.fir - b.sec);
}

void solve() {
    int n, m, x, l = 1;
    cin >> n >> m >> x;
    int r = n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].fir >> a[i].sec;
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i].fir >> b[i].sec;
    }
    int ans = 0;
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m, cmp);
    for (int i = 1; i <= m; i++) {
        if (b[i].fir == b[i].sec) {
            ans += (b[i].sec * x);
        } else if (b[i].fir > b[i].sec){
            if (a[l].sec <= 0) l++;
            ans += (b[i].sec * x + (b[i].fir -b[i].sec) * a[l].fir);
            a[l].sec--;   
        } else {
            if (a[r].sec <= 0) r--;     
            ans += (b[i].sec * x + (b[i].fir -b[i].sec) * a[r].fir);
            a[r].sec--;
        }
    }   
    cout << ans * 2;
}

signed main() {
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