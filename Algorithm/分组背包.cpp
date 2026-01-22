#include<bits/stdc++.h>
#define ll long long

using namespace std;

int Groupbackpack(int W, vector<vector<pair<int, int>>> &groups) { // first -> wi second -> vi
    vector<int> dp(W + 1);
    for (auto group : groups) { // 遍历每组
        for (int j = W; j >= 0; j--) { 
            for (auto item : group) {
                if (j >= item.first) {
                    dp[j] = max(dp[j], dp[j - item.first] + item.second);
                }
            }
        }
    }
    return dp[W];
}

void test() {
    int n, W;
    vector<vector<pair<int, int>>> groups;
    cin >> n >> W;
    for (int i = 1; i <= n; i++) {
        int m;
        cin >> m;
        vector<pair<int, int>> group;
        for (int j = 1; j <= m; j++) {
            int wi, vi;
            cin >> wi >> vi;
            group.push_back({wi, vi});
        }
        groups.push_back(group);
    } 
    cout << Groupbackpack(W, groups);
}

/*
3
2
1 2
2 4
2
3 4
1 5
1
2 3
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // freopen("xxx.in", "r", stdin);
    // freopen("xxx.out", "w", stdout);

    int T = 1; // cin >> T;
    while(T--) {
        test();
    }

    return 0;
}