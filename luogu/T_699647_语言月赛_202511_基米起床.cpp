#include<bits/stdc++.h>
#define ll long long

using namespace std;

char a[505][505];

void solve() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i % 2 == 1) {
                if (j % 4 == 1 && j != 1) {
                    a[i][j] = '.';
                } else {
                    a[i][j] = 'x';
                }
            } else {
                if (j % 4 == 0 && j != m) {
                    a[i][j] = '.';
                } else {
                    a[i][j] = 'x';
                }
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << a[i][j];
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int T = 1;
    while(T--) {
        solve();
    }
    
    return 0;
}