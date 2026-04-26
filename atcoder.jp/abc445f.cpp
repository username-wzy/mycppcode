#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 305;
int n, A, B;
string s[N];
int id[N][N];
vector<int> g[N * N];
int mx[N * N], my[N * N];
int vis[N * N];
int cntx, cnty;
vector<pair<int, int>> px, py;

bool dfs(int x)
{
    for (int y : g[x]) {
        if (vis[y])
            continue;
        vis[y] = 1;
        if (!my[y] || dfs(my[y])) {
            mx[x] = y;
            my[y] = x;
            return 1;
        }
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> A >> B;
    for (int i = 1; i <= n; i++)
        cin >> s[i];

    int dx8[8] = { A, B, B, A, -A, -B, -B, -A };
    int dy8[8] = { B, A, -A, -B, -B, -A, A, B };

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i][j - 1] == '.') {
                if ((i + j) & 1) {
                    id[i][j] = ++cntx;
                    px.push_back({ i, j });
                } else {
                    id[i][j] = ++cnty;
                    py.push_back({ i, j });
                }
            }
        }
    }

    for (int i = 0; i < px.size(); i++) {
        int x = px[i].first;
        int y = px[i].second;
        for (int k = 0; k < 8; k++) {
            int xx = x + dx8[k];
            int yy = y + dy8[k];
            if (xx >= 1 && xx <= n && yy >= 1 && yy <= n) {
                if (s[xx][yy - 1] == '.' && ((xx + yy) % 2 == 0)) {
                    g[i + 1].push_back(id[xx][yy]);
                }
            }
        }
    }

    int match = 0;
    for (int i = 1; i <= cntx; i++) {
        memset(vis, 0, sizeof(int) * (cnty + 1));
        if (dfs(i))
            match++;
    }

    vector<int> vx(cntx + 1), vy(cnty + 1);
    queue<int> q;

    for (int i = 1; i <= cntx; i++) {
        if (!mx[i]) {
            vx[i] = 1;
            q.push(i);
        }
    }

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int y : g[x]) {
            if (!vy[y] && mx[x] != y) {
                vy[y] = 1;
                if (my[y] && !vx[my[y]]) {
                    vx[my[y]] = 1;
                    q.push(my[y]);
                }
            }
        }
    }

    vector<vector<int>> bad(n + 1, vector<int>(n + 1));

    for (int i = 0; i < px.size(); i++) {
        int x = px[i].first;
        int y = px[i].second;
        if (vx[i + 1])
            bad[x][y] = 1;
    }

    for (int i = 0; i < py.size(); i++) {
        int x = py[i].first;
        int y = py[i].second;
        if (!vy[i + 1])
            bad[x][y] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i][j - 1] == '#')
                cout << '#';
            else if (bad[i][j])
                cout << '.';
            else
                cout << 'o';
        }
        cout << '\n';
    }
    return 0;
}
