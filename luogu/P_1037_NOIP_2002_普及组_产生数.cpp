#include<bits/stdc++.h>
#define ll long long

using namespace std;

bool a[15][15];
int b[15];

void out(__int128 x){
	if(x > 9) out(x / 10);
	putchar(x % 10 + '0');
}

void solve() {
    string s;
    int k;
    cin >> s >> k;
    for (int i = 1; i <= k; i++) {
        int u, v;
        cin >> u >> v;
        a[u][v] = 1;
    }
    for (int i = 0; i <= 9; i++) {
        a[i][i] = 1;
    }
    for (int k = 1; k <= 9; k++) {
        for (int i = 0; i <= 9; i++) {
            for (int j = 1; j <= 9; j++) {
                if (a[i][k] && a[k][j]) {
                    a[i][j] = 1;
                }
            }
        }
    }
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            if (a[i][j]) b[i]++;
        }
    }
    __int128 sum = 1;
    for (int i = 0; i < s.size(); i++) {
        sum *= b[s[i] - '0'];
    }
    out(sum);
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