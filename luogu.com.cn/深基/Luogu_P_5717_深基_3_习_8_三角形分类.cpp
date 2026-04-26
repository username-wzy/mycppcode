#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    if (a > b) swap(a, b);
    if (b > c) swap(b, c);

    if (a + b <= c) {
        cout << "Not triangle\n";
        return ;
    }
    
    if (a * a + b * b == c * c) 
        cout << "Right triangle\n";

    if (a * a + b * b > c * c) 
        cout << "Acute triangle\n";
  
    if (a * a + b * b < c * c) 
        cout << "Obtuse triangle\n";

    if (a == b || a == c || b == c)
        cout << "Isosceles triangle\n";

    if (a == b && b == c)
        cout << "Equilateral triangle\n";
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