#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 100005;

int dp[N][20];
int log_2[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> dp[i][0];
    for (int i = 2; i <= n; i++) {
        log_2[i] = log_2[i >> 1] + 1;
    }
    int logn = log_2[n];
    for (int j = 1; j <= logn; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            dp[i][j] = max(dp[i][j - 1], dp[i + (1 << j - 1)][j - 1]);
        }
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        int loglr = log_2[r - l + 1];
        cout << max(dp[l][loglr], dp[r - (1 << loglr) + 1][loglr]) << '\n';
    }
    return 0;
}