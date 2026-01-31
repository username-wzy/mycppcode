#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int in[MAXN], n, m;
vector<int> g[MAXN];

void topoSort()
{
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (in[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        cout << u << " ";
        q.pop();
        for (int v : g[u]) {
            in[v]--;
            if (in[v] == 0) {
                q.push(v);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int u = 1; u <= n; ++u) {
        int v;
        while (cin >> v) {
            if (v == 0)
                break;
            g[u].push_back(v);
            in[v]++;
        }
    }
    topoSort();
    return 0;
}