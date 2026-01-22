#include<bits/stdc++.h>
#define ll long long

using namespace std;

int w[10005], v[10005], dp[50005];

int bitdp(int n, int W, vector<int>& w, vector<int>& v, vector<int>& s) {
    vector<pair<int,int>> items; // (weight, value)
    
    // 二进制拆分
    for (int i = 1; i <= n; ++i) {
        int cnt = s[i];
        for (int k = 1; k <= cnt; k *= 2) {
            items.emplace_back(k * w[i], k * v[i]);
            cnt -= k;
        }
        if (cnt)
            items.emplace_back(cnt * w[i], cnt * v[i]);
    }
    
    // 01背包求解
    vector<int> dp(W + 1, 0);
    for (auto it : items) {
        for (int j = W; j >= it.first; --j) {
            dp[j] = max(dp[j], dp[j - it.first] + it.second);
        }
    }
    return dp[W];
}

void solve() {
    // 例如 如果一个物品为v:1, w:5, s:10
    /*
        将这种物品的数量
        换成
        10 = 2^0 + 2^1 + 2^2 + 3
        为什么是2进制分解 {
            1.要转换成01背包
            2.2进制可以表示所有的数
        }
    */
    int n, W;
    cin >> n >> W;
    vector<int> w(n + 1), v(n + 1), s(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i] >> s[i];
    }
    cout << bitdp(n, W, w, v, s);
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