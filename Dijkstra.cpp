w#include<bits/stdc++.h>
#define ll long long

using namespace std;

vector<pair<int, int>> g[105]; 
int n, m;

int dijkstra(int s, int e) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, s});
	vector<int> dis(n + 1, 1e9), vis(n + 1);
	dis[s] = 0;
	while (!pq.empty()) {
		auto u  = pq.top().second;
		pq.pop();
		for (auto [v, ww] : g[u]) {
			if (!vis[v]) {
				if (dis[u] + ww < dis[v]) {
					dis[v] = dis[u] + ww;
					pq.push({dis[v], v});
				}
			}
		}
	}
	return dis[e];
}

void solve() {
   cin >> n >> m;
   for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
   }
   cout << dijkstra(1, 4);
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
/*
4 5
1 2 3
1 3 1
1 4 5
2 4 6
3 4 2
*/
