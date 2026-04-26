#include<bits/stdc++.h>
#define ll long long

using namespace std;

struct node {
    int u, v, w;
    bool operator< (const node other) const {
        return w < other.w;
    }
};

vector<node> g;

int fa[305];

int find(int x) {
    if (fa[x] == x) return x;
    else return fa[x] = find(fa[x]);
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int w;
        cin >> w;
        g.push_back({0, i, w});
    }
    for (int i = 1 ; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int w;
            cin >> w;
            if (i != j) {
                g.push_back({i, j, w});
            }
        }
    }
    sort(g.begin(), g.end());
    for (int i = 0; i <= n; i++) {
        fa[i] = i;
    }
    int sum = 0, cnt = 0;
    for (auto it : g) {
        int u = it.u, v = it.v, w = it.w;
        int fu = find(u), fv = find(v);
        if (fu != fv) {
            fa[fv] = fu;
            sum += w;
            cnt++;
        }
        if (cnt >= n) {
            break;
        }
    }
    cout << sum;
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