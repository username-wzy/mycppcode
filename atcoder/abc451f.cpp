#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 2e5 + 5;

int fa[N]; // 我是你baba
int cnt[N][2]; // cnt[u][0 or 1] 表示以u为根节点的连通块同色与异色的数量
bool dist[N]; // 这个点是黑还是白
int ans = 0;
bool ok = true; // 奇环

int find(int x)
{
    if (fa[x] == x)
        return x;
    int root = find(fa[x]);
    dist[x] ^= dist[fa[x]];
    return fa[x] = root;
}

bool unite(int x, int y)
{
    int rx = find(x);
    int ry = find(y);
    if (rx != ry) {
        // 1. 先减去合并前的贡献
        ans -= min(cnt[rx][0], cnt[rx][1]);
        ans -= min(cnt[ry][0], cnt[ry][1]);

        // 2. 确定 rx 相对 ry 的偏移量
        int d_rx = dist[x] ^ dist[y] ^ 1;
        dist[rx] = d_rx;
        fa[rx] = ry;
        // 合并rx到ry：路径rx->x->y->ry，异或叠加得d[rx] = d[x]^1^d[y]
        // 若d[rx]=1则rx块相对ry翻转，cnt需交叉累加；否则平行累加

        // 3. 根据偏移量合并计数到新根 ry 上
        if (d_rx == 0) { //
            cnt[ry][0] += cnt[rx][0]; // 相同颜色直接加
            cnt[ry][1] += cnt[rx][1]; // too
        } else {
            cnt[ry][0] += cnt[rx][1]; // 不同颜色对着加
            cnt[ry][1] += cnt[rx][0]; // too
        }

        // 4. 加上合并后的新贡献
        ans += min(cnt[ry][0], cnt[ry][1]);
        return true;
    }

    // 如果 rx == ry，说明已经在同一连通块，检查是否冲突
    if (dist[x] == dist[y]) {
        ok = false; // 发现奇环，标记非法
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        cnt[i][0] = 1;
    }

    while (q--) {
        int u, v;
        cin >> u >> v;
        unite(u, v);
        if (!ok) {
            cout << "-1\n";
        } else
            cout << ans << '\n';
    }
    return 0;
}