#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    double m, h;
    cin >> m >> h;
    double bmi = m / (h * h);
    if (bmi < 18.5) cout << "Underweight";
    else if (bmi >= 18.5 && bmi < 24) cout << "Normal";
    else cout << bmi << '\n' << "Overweight";
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