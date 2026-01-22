#include<bits/stdc++.h>
#define ll long long

using namespace std;

struct ITEM {
    int w, v, type; // 当type为-1时会使用01背包，si为0时使用完全背包
};

void solve() {
    // -1 为 01 0为完全 >0为多重
    int n, W, wi, vi, si;
    vector<ITEM> items;
    cin >> n >> W;
    vector<int> dp(W + 1);
    while (n--) {
        cin >> wi >> vi >> si;
        if (si == -1 || si == 0) items.push_back({wi, vi, si});
        else{
            for (int i = 1; i < si; i *= 2) { // 二进制分解转换成01背包
                items.push_back({i * wi, i * vi, -1});
                si -= i;    
            }  
            items.push_back({si * wi, si * vi, - 1});
        }
    }
    for (auto i : items) {
        if (i.type == -1) {
            for (int j = W; j >= i.w; j--) {
                dp[j] = max(dp[j], dp[j - i.w] + i.v);
            }
        } else {
            for (int j = i.w; j <= W; j++) {
                dp[j] = max(dp[j], dp[j - i.w] + i.v);
            }
        }
    }
    cout << dp[W];
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