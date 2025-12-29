#include<bits/stdc++.h>
#define ll long long

using namespace std;

struct node {
    int x, y, id; // id 当前牧区的所属牧场
};

int n;
node a[155];
bool b[155][155];
double dis[155][155], maxdis[155], d[155]; // d[i]表示连接i号点所得到的最大直径 maxdis[i]表示i号点所在联通块的直径

double getdis(node a, node b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)); // 计算两点距离
}

void dfs(int u, int id) {
    a[u].id = id; // 标记所属牧场
    for (int v = 1; v <= n; v++) {
        if (b[u][v] && !a[v].id) { // 直接相连且还没有分配牧场
            dfs(v, id);
        }
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char c;
            cin >> c;
            b[i][j] = (c == '1');
            if (b[i][j]) {
                dis[i][j] = getdis(a[i], a[j]); // 直接相连
            } else if (i != j) dis[i][j] = 1e18; // 不直接相连
            else dis[i][j] = 0; // 自己到自己的距离为0
        }
    }
    // 分牧场
    for (int i = 1; i <= n; i++) {
        if (a[i].id == 0) { // 还没有分配牧场
            dfs(i, i);
        }
    }
    
    // for (int i = 1; i <= n; i++) {
    //     cerr << a[i].x << " " << a[i].y << " " << a[i].id << "\n";
    // }
    // floyd
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (dis[i][k] == INT_MAX) continue; // 优化
            for (int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    // 计算每个牧场的直径和每个点到本牧场内其他点的最大距离
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j && a[i].id == a[j].id) { // 在同一个牧场内
                maxdis[i] = max(maxdis[i], dis[i][j]); // 计算i点到本牧场内其他点的最大距离
                d[a[i].id] = max(d[a[i].id], dis[i][j]); // 计算牧场的直径
            }
        }
    }
    // 枚举两个牧区，判断是否不在一个牧场内，计算答案
    double ans = 1e18;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i].id != a[j].id) { // 不在同一个牧场内
                ans = min(max({maxdis[i] + maxdis[j] + getdis(a[i], a[j]), d[a[i].id], d[a[j].id]}), ans); // 三种情况取最大值，再在所有情况中取最小值
                // 第一种：连接i和j所得到的直径
                // cerr << i << " " << j << " " << max({maxdis[i] + maxdis[j] + getdis(a[i], a[j]), d[a[i].id], d[a[j].id]}) << "\n";
                // 第二种：i所在牧场的直径
                // cerr << i << " " << j << " " << d[a[i].id] << "\n";
                // 第三种：j所在牧场的直径
                // cerr << i << " " << j << " " << d[a[j].id] << "\n";
            }
        }
    }
    cout << fixed << setprecision(6) << ans;
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