#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    int* nxt = new int[m + 5];
    for (int i = 1, j = 0; i < m; i++) {
        while (j && b[i] != b[j]) {
            j = nxt[j - 1];
        }
        if (b[i] == b[j])
            j++;
        nxt[i] = j;
    }
    for (int i = 0, j = 0; i < n; i++) {
        while (j && a[i] != b[j])
            j = nxt[j - 1];
        if (a[i] == b[j])
            j++;
        if (j == m) {
            cout << "zdl:" << i - m + 1 << '\n';
            j = nxt[j - 1];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // freopen("xxx.in", "r", stdin);
    // freopen("xxx.out", "w", stdout);

    int T = 1; // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}