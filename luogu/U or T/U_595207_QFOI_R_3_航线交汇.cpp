#include<bits/stdc++.h>
using namespace std;

struct plane {
    long long s, t, h;
    void input() {
        cin >> s >> t >> h;
    }
};

plane a[100005];

void solve() {
    int n;
    long long d;
    cin >> n >> d;
    
    for (int i = 0; i <= n; ++i) {
        a[i].input();
    }
    
    plane xiaor = a[0];
    long long speed1 = xiaor.s - xiaor.t;
    
    for (int i = 1; i <= n; ++i) {
        plane other = a[i];
        long long speedi = other.s - other.t;
        if (abs(other.h - xiaor.h) > d || speedi == speed1 && xiaor.s != other.s) {
            cout << "No\n";
        } else if (other.s == xiaor.s && other.t == xiaor.t) {
            cout << "Always\n";
        } else {
            double x = (xiaor.s - other.s) * 1.0 / (xiaor.s - xiaor.t - (other.s - other.t));
            if (x >= 0 &&  x <= 1) cout << fixed << setprecision(12) << xiaor.s + (xiaor.t - xiaor.s) * x << '\n';
            else cout << "No\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(12);
    
    int T = 1; 
    while (T--) {
        solve();
    }
    
    return 0;
}