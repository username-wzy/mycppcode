#include <bits/stdc++.h>
using namespace std;

struct E {
    int to;
    unsigned char w; // 0 or 1
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int S = 0;
    int N = n + m; // nodes: 1..n are stations, n+1..n+m are train virtual nodes
    int V = N + 1; // plus source 0

    vector<vector<E>> adj(V);
    vector<vector<int>> rev0(V); // reverse edges for w==0 only

    auto addEdge = [&](int u, int v, int w) {
        adj[u].push_back({ v, (unsigned char)w });
        if (w == 0)
            rev0[v].push_back(u);
    };

    // source edges: level(v) >= 1
    for (int v = 1; v <= N; v++)
        addEdge(S, v, 1);

    vector<int> stops;
    vector<char> isStop(n + 1, 0);

    for (int i = 1; i <= m; i++) {
        int si;
        cin >> si;
        stops.clear();
        stops.reserve(si);
        for (int k = 0; k < si; k++) {
            int x;
            cin >> x;
            stops.push_back(x);
            isStop[x] = 1;
        }
        int L = stops.front();
        int R = stops.back();
        int Ti = n + i;

        // non-stop stations in [L,R] must be < Ti  => Ti >= x + 1  => edge x->Ti (1)
        for (int x = L; x <= R; x++) {
            if (!isStop[x])
                addEdge(x, Ti, 1);
        }

        // Ti is min among stops: stop >= Ti => edge Ti->stop (0)
        for (int s : stops)
            addEdge(Ti, s, 0);

        // unmark
        for (int s : stops)
            isStop[s] = 0;
    }

    // Kosaraju on 0-weight edges:
    vector<char> vis(V, 0);
    vector<int> order;
    order.reserve(V);

    // forward DFS uses adj filtered by w==0
    for (int st = 0; st < V; st++) {
        if (vis[st])
            continue;
        // iterative DFS
        vector<pair<int, int>> stck;
        stck.push_back({ st, 0 });
        vis[st] = 1;

        while (!stck.empty()) {
            int u = stck.back().first;
            int& it = stck.back().second;
            bool pushed = false;
            while (it < (int)adj[u].size()) {
                auto e = adj[u][it++];
                if (e.w != 0)
                    continue;
                int v = e.to;
                if (!vis[v]) {
                    vis[v] = 1;
                    stck.push_back({ v, 0 });
                    pushed = true;
                    break;
                }
            }
            if (!pushed) {
                order.push_back(u);
                stck.pop_back();
            }
        }
    }

    vector<int> comp(V, -1);
    int compCnt = 0;

    for (int idx = V - 1; idx >= 0; idx--) {
        int v = order[idx];
        if (comp[v] != -1)
            continue;

        // DFS on reverse 0-edges
        stack<int> st;
        st.push(v);
        comp[v] = compCnt;

        while (!st.empty()) {
            int u = st.top();
            st.pop();
            for (int p : rev0[u]) {
                if (comp[p] == -1) {
                    comp[p] = compCnt;
                    st.push(p);
                }
            }
        }
        compCnt++;
    }

    // Build condensed DAG with all edges (0/1), between components
    vector<vector<E>> cadj(compCnt);
    vector<int> indeg(compCnt, 0);

    for (int u = 0; u < V; u++) {
        int cu = comp[u];
        for (auto e : adj[u]) {
            int v = e.to;
            int cv = comp[v];
            if (cu == cv)
                continue;
            cadj[cu].push_back({ cv, e.w });
            indeg[cv]++;
        }
    }

    // Topo + longest path DP
    const int NEG = -1e9;
    vector<int> dp(compCnt, NEG);
    dp[comp[S]] = 0;

    queue<int> q;
    for (int c = 0; c < compCnt; c++)
        if (indeg[c] == 0)
            q.push(c);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto e : cadj[u]) {
            int v = e.to;
            if (dp[u] != NEG)
                dp[v] = max(dp[v], dp[u] + (int)e.w);
            if (--indeg[v] == 0)
                q.push(v);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[comp[i]]);
    }
    cout << ans << "\n";
    return 0;
}
