// 满意方案数 = 总方案 - (非法CP组合数 × K) - (非法PS组合数 × N) + (同时包含CP和PS的非法组合数)
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k, p;
    cin >> n >> m >> k >> p;
    vector<int> cp(m + 1), ps(m + 1);
    set<pair<int, int>> cp_set, ps_set;
    for (int i = 0; i < p; i++) {
        string t;
        int x, y;
        cin >> t >> x >> y;
        if (t == "CP") {
            if (cp_set.find({ x, y }) == cp_set.end()) {
                cp_set.insert({ x, y });
                cp[y]++;
            }
        } else {
            if (ps_set.find({ x, y }) == ps_set.end()) {
                ps_set.insert({ x, y });
                ps[x]++;
            }
        }
    }
    long long ans = 0;
    for (int j = 1; j <= m; j++) {
        long long cloth = n - cp[j];
        long long shoe = k - ps[j];
        ans += cloth * shoe;
    }
    cout << ans;
}