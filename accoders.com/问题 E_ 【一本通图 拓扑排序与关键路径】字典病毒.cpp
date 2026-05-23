#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<char> g[200];
int in[200];
char mp[200];
bool vis[200];

void topo_sort()
{
    queue<int> q;
    for (int i = 'a'; i <= 'z'; i++) {
        if (in[i] == 0 && vis[i]) {
            q.push(i);
        }
    }
    vector<char> topo;
    while (!q.empty()) {
        int u = q.front();
        topo.push_back(u);
        if (q.size() > 1) {
            cout << "0";
            exit(0);
        }

        q.pop();

        for (int v : g[u]) {
            if ((--in[v]) == 0) {
                q.push(v);
            }
        }
    }
    for (int i = 'a'; i <= 'z'; i++) {
        if (in[i] != 0) {
            cout << 0;
            exit(0);
        }
    }
    vector<char> sort_topo = topo;
    sort(sort_topo.begin(), sort_topo.end());
    for (int i = 0; i < topo.size(); i++) {
        mp[topo[i]] = sort_topo[i];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> k;

    string last, s;
    cin >> last;

    for (int i = 1; i < k; i++) {
        cin >> s;
        for (int i = 0; i < min(last.size(), s.size()); i++) {
            if (last[i] != s[i]) {
                g[last[i]].push_back(s[i]);
                vis[last[i]] = vis[s[i]] = true;
                // cerr << last[i] << "->" << s[i] << '\n';
                in[s[i]]++;
                break;
            }
        }
        last = s;
    }

    topo_sort();

    string s2;
    cin >> s2;
    for (int i = 0; i < s2.size(); i++) {
        if (!isalpha(mp[s2[i]])) {
            cout << 0;
            exit(0);
        }
    }
    for (int i = 0; i < s2.size(); i++) {
        cout << mp[s2[i]];
    }
    return 0;
}