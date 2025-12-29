#include<bits/stdc++.h>
#define ll long long

using namespace std;

int n;
string s, a, b, c, d, e;
void solve() {
    cin >> n >> s;
    n --;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            a += "XXX";
            b += "X.X";
            c += "X.X";
            d += "X.X";
            e += "XXX";
        } else if (s[i] == '1') {
            a += "..X";
            b += "..X";
            c += "..X";
            d += "..X";
            e += "..X";
        } else if (s[i] == '2') {
            a += "XXX";
            b += "..X";
            c += "XXX";
            d += "X..";
            e += "XXX";
        } else if (s[i] == '3') {
            a += "XXX";
            b += "..X";
            c += "XXX";
            d += "..X";
            e += "XXX";
        } else if (s[i] == '4') {
            a += "X.X";
            b += "X.X";
            c += "XXX";
            d += "..X";
            e += "..X";
        } else if (s[i] == '5') {
            a += "XXX";
            b += "X..";
            c += "XXX";
            d += "..X";
            e += "XXX";
        } else if (s[i] == '6') {
            a += "XXX";
            b += "X..";
            c += "XXX";
            d += "X.X";
            e += "XXX";
        } else if (s[i] == '7') {
            a += "XXX";
            b += "..X";
            c += "..X";
            d += "..X";
            e += "..X";
        } else if (s[i] == '8') {
            a += "XXX";
            b += "X.X";
            c += "XXX";
            d += "X.X";
            e += "XXX";
        } else if (s[i] == '9') {
            a += "XXX";
            b += "X.X";
            c += "XXX";
            d += "..X";
            e += "XXX";
        }
        if (n > 0) {
            a += '.';
            b += '.';
            c += '.';
            d += '.';
            e += '.';
        }
        n--;
    }
    cout << a << '\n' << b << '\n' << c << '\n' << d << '\n' << e;
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