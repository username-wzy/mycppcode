#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

const int N = 50005;

struct Edge {
    int v;
    int w;
};

vector<Edge> g[N];
int n, m;
int up[N][18], pos[N];
ll dist[N][18];
bool is_control[N], has_jundui[N];
bool used[N];

// 预处理倍增数组
void pre_dfs(int u, int fa, int w)
{
    up[u][0] = fa;
    dist[u][0] = w;
    for (int i = 1; i <= 17; i++) {
        up[u][i] = up[up[u][i - 1]][i - 1];
        dist[u][i] = dist[u][i - 1] + dist[up[u][i - 1]][i - 1];
    }
    for (auto& edge : g[u]) {
        if (edge.v != fa)
            pre_dfs(edge.v, u, edge.w);
    }
}

// 检查以 u 为根的子树是否已被完全控制
bool check_dfs(int u, int fa)
{
    if (is_control[u])
        return true;
    bool is_leaf = true;
    for (auto& edge : g[u]) {
        if (edge.v == fa)
            continue;
        is_leaf = false;
        if (!check_dfs(edge.v, u))
            return false;
    }
    return !is_leaf; // 如果是叶子且未被控制，返回 false
}

bool check(ll limit)
{
    memset(is_control, 0, sizeof is_control);
    vector<pair<ll, int>> freee;
    vector<pair<ll, int>> needs;

    // 1. 全军出击
    for (int i = 1; i <= m; i++) {
        int cuur_u = pos[i];
        ll curr_time = limit;
        for (int k = 17; k >= 0; k--) {
            if (up[cuur_u][k] > 1 && dist[cuur_u][k] <= curr_time) {
                curr_time -= dist[cuur_u][k];
                cuur_u = up[cuur_u][k];
            }
        }

        // 如果能跳到根节点的子节点且还能到根节点
        if (up[cuur_u][0] == 1 && curr_time >= dist[cuur_u][0]) {
            freee.push_back({ curr_time - dist[cuur_u][0], cuur_u });
        } else {
            is_control[cuur_u] = true;
        }
    }

    // 2. 检查哪些子树没被封锁
    if (check_dfs(1, 0))
        return true;

    for (auto& edge : g[1]) {
        if (!check_dfs(edge.v, 1)) {
            needs.push_back({ (ll)edge.w, edge.v });
        }
    }

    // 3. 贪心匹配：处理富余军队
    sort(freee.begin(), freee.end());
    sort(needs.begin(), needs.end());

    // 标记哪些需要覆盖的子树可以不动就地解决
    memset(used, 0, sizeof(bool) * (freee.size() + 1));

    // 关键优化：如果一支军队能回到根节点再回来，但它所在的子树还没被封锁，优先让它守在原地
    static bool subtree_needed[N];
    memset(subtree_needed, 0, sizeof subtree_needed);
    for (auto& p : needs)
        subtree_needed[p.second] = true;

    vector<ll> final_free;
    for (int i = 0; i < freee.size(); i++) {
        // 如果这支军队来源的子树需要覆盖，且它的剩余时间不足以让它去支援别人再回来（或者就地守最划算）
        if (subtree_needed[freee[i].second] && freee[i].first < dist[freee[i].second][0]) {
            subtree_needed[freee[i].second] = false; // 视作已解决
        } else {
            final_free.push_back(freee[i].first);
        }
    }

    // 重新收集真正还需要的子树
    vector<ll> final_needs;
    for (auto& p : needs) {
        if (subtree_needed[p.second])
            final_needs.push_back(p.first);
    }

    if (final_free.size() < final_needs.size())
        return false;

    sort(final_free.begin(), final_free.end());
    sort(final_needs.begin(), final_needs.end());

    int i = 0, j = 0;
    while (i < final_free.size() && j < final_needs.size()) {
        if (final_free[i] >= final_needs[j]) {
            i++;
            j++;
        } else {
            i++;
        }
    }
    return j == final_needs.size();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> n))
        return 0;
    ll l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({ v, w });
        g[v].push_back({ u, w });
        r += w;
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
        cin >> pos[i];

    // 如果军队数少于根节点的出度，必然无法封锁
    pre_dfs(1, 0, 0);
    int root_deg = g[1].size();
    if (m < root_deg) {
        cout << -1 << endl;
        return 0;
    }

    ll ans = -1;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}