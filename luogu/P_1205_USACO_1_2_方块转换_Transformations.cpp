#include<bits/stdc++.h>
#define ll long long

using namespace std;

bool check(char a[15][15], char b[15][15], int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] != b[i][j]) return false;
        }
    }
    return true;
}

void solve() {
    char a[15][15], b[7][15][15], c[15][15];
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            b[0][j][n-i+1] = a[i][j];
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            b[1][n-i+1][n-j+1] = a[i][j];
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            b[2][n-j+1][i] = a[i][j];
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            b[3][i][n-j+1] = a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            b[4][j][n-i+1] = b[3][i][j];
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            b[5][n-i+1][n-j+1] = b[3][i][j];
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            b[6][n-j+1][i] = b[3][i][j];
        }
    }
    
    
    for (int i = 0; i < 3; i++) {
        if (check(b[i], c, n)) {
            cout << i + 1;
            return;
        }
    }
    
    
    if (check(b[3], c, n)) {
        cout << 4;
        return;
    }
    
    for (int i = 4; i < 7; i++) {
        if (check(b[i], c, n)) {
            cout << 5;
            return;
        }
    }
    
    if (check(a, c, n)) {
        cout << 6;
        return;
    }
    
    cout << 7;
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