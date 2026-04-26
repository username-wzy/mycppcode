#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<pair<int, int>> g[100005];
int in[100005];
int pre[100005], dis[100005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({ v, w });
        in[v]++;
    }

    priority_queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.top();
        q.pop();
        for (auto p : g[u]) {
            int v = p.first, w = p.second;
            if (dis[u] + w > dis[v]) {
                dis[v] = dis[u] + w;
                pre[v] = u;
            } else if (dis[u] + w == dis[v] && u < pre[v]) {
                pre[v] = u;
            }
            if ((--in[v]) == 0) {
                q.push(v);
            }
        }
    }
    vector<int> ans2;
    int ed = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        if (dis[i] > ans) {
            ans = dis[i];
            ed = i;
        }
    }
    while (ed != 0) {
        ans2.push_back(ed);
        ed = pre[ed];
    }
    cout << ans << '\n';
    for (int i = ans2.size() - 1; i >= 0; i--) {
        cout << ans2[i] << " ";
    }
    return 0;
}