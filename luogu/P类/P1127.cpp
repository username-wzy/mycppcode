#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 20005;

int in[N], out[N], cur[N];
vector<pair<int, string>> g[N];
vector<string> ans;

void dfs(int u)
{
    while (cur[u] < g[u].size()) {
        int v = g[u][cur[u]].first;
        string e = g[u][cur[u]].second;
        cur[u]++;
        dfs(v);
        ans.push_back(e);
    }
}

bool cmp(pair<int, string> a, pair<int, string> b)
{
    return a.second < b.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        int st = s[0], ed = s.back();
        in[ed]++;
        out[st]++;
        g[st].push_back({ ed, s });
    }
    for (int i = 1; i <= N; i++)
        sort(g[i].begin(), g[i].end(), cmp);
    int st = 0, ed = 0, st_idx = 0, other = 0;
    for (int i = 1; i <= N; i++) {
        if (in[i] == out[i])
            continue;
        if (in[i] - out[i] == 1)
            ed++;
        else if (out[i] - in[i] == 1) {
            st_idx = i;
            st++;
        } else
            other++;
    }
    if (st_idx == 0) {
        for (int i = 1; i <= N; i++) {
            if (g[i].size()) {
                st_idx = i;
                break;
            }
        }
    }
    if (st == 1 && ed == 1 && other == 0) {
        dfs(st_idx);
        if (ans.size() != n) {
            cout << "***";
            return 0;
        }
        for (int i = ans.size() - 1; i >= 1; i--) {
            cout << ans[i] << ".";
        }
        cout << ans[0];
    } else if (st == 0 && ed == 0 && other == 0) {
        dfs(st_idx);
        if (ans.size() != n) {
            cout << "***";
            return 0;
        }
        for (int i = ans.size() - 1; i >= 1; i--) {
            cout << ans[i] << ".";
        }
        cout << ans[0];
    } else
        cout << "***";
    return 0;
}