#include<bits/stdc++.h>
#define ll long long

using namespace std;

constexpr int N = 1e5 + 5;

vector<int> g[N];
int ans = 0;

int bfs(int x, int target) {
    
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    int q, i = 1; cin >> q;
    while (q--) {
        int pi;
        cin >> pi;
        cout << bfs(i, pi);;
    }
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