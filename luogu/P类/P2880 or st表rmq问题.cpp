#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

constexpr int N = 5e4 + 5;
constexpr int L = 20; // ceil(log2(10^6))

int stmax[N][L], stmin[N][L];
int log_2[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // st tabel
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> stmax[i][0];
        stmin[i][0] = stmax[i][0];
    }

    for (int i = 2; i <= n; i++) {
        log_2[i] = log_2[i >> 1] + 1;
    }

    for (int k = 1; (1 << k) <= n; k++) {
        for (int i = 1; i + (1 << k) - 1 <= n; i++) {
            stmax[i][k] = max(stmax[i][k - 1], stmax[i + (1 << (k - 1))][k - 1]);
            stmin[i][k] = min(stmin[i][k - 1], stmin[i + (1 << (k - 1))][k - 1]);
        }
    }

    while (q--) {
        int x, y;
        cin >> x >> y;
        const int k = log_2[y - x + 1];
        cout << max(stmax[x][k], stmax[y - (1 << k) + 1][k]) - min(stmin[x][k], stmin[y - (1 << k) + 1][k]) << '\n';
    }
    return 0;
}