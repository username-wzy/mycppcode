#include<bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e5 + 5;
ll n, m, a, b, in[N], out[N], ans[N];
vector<ll> g[N];
queue<ll> q;

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        out[a]++;
        in[b]++;
        g[a].push_back(b);
    }
    for (int i = 1; i <= n; i++) {
        if (!in[i]) {
            ans[i] = 1;
            q.push(i);
        }
    }
    while (!q.empty()) {
        ll u = q.front();
        q.pop();
        for (int i = 0; i < g[u].size(); i++) {
            ll v = g[u][i];
            in[v]--;
            if (!in[v]) {
                ans[v] = ans[u] + 1;
                q.push(v);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    //freopen("xxx.in", "r", stdin);
    //freopen("xxx.out", "w", stdout);
    int T = 1; //cin >> T;
    while (T--) {
        solve();
    }
    
    return 0;
}
