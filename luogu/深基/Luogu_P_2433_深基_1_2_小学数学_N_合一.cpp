#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int x;
    cin >> x;
    switch (x) {
        case 1:{
            cout << "I love Luogu!";
            break;}
        case 2:{
            cout << 6 << " " << 4;
            break;}
        case 3:{
            cout << 3 << "\n" << 12 << "\n" << 2;
            break;}
        case 4:{
            cout << 166.666666;
            break;}
        case 5:{
            cout << 15;
            break;}
        case 6:{
            cout << sqrt(6 * 6 + 9 * 9);
            break;}
        case 7:{
            cout << 110 << '\n' << 90 << '\n' << 0;
            break;}
        case 8:{
            cout << "31.4159\n78.5398\n523.599";
            break;}
        case 9:{
            cout << (((1 + 1) * 2 + 1) * 2 + 1) * 2;
            break;}
        case 10:{
            cout << 9;
            break;}
        case 11:{
            cout << 100.0 / 3;
            break;}
        case 12:{
            cout << 13 << '\n';
            cout << 'R';
            break;}
        case 13: {
            double v = 4.0 / 3 * 3.141593 * 4 * 4 * 4 + 4.0 / 3 * 3.141593 * 10 * 10 * 10;
            v = pow(v, 1.0 / 3);
            cout << int(round(v));
            break;
        }
        case 14: {
            cout << 50;
            break;
        }
        default:
            break;
    }
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0), cout.tie(0);

    // freopen("xxx.in", "r", stdin);
    // freopen("xxx.out", "w", stdout);

    int T = 1; // cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}