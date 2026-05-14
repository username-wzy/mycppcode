#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;
#define IAK std::ios::sync_with_stdio(false);
#define IOI std::cin.tie(nullptr)
using namespace std;
using ll = long long;

const int N = 105;

ll dist[N][N];

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> orange;
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        orange.push_back(x);
    }
    memset(dist, 0x3f, sizeof dist);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            dist[i][j] = x;
        }
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    int last = orange[0];
    ll cnt = 0;
    for (int i = 1; i < m; i++) {
        int x = orange[i];
        cnt += dist[last][x];
        last = x;
    }
    cout << cnt;
}

int main()
{
    IAK IOI;
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}