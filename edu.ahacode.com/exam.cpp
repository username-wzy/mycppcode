#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 2e6 + 5;

int fa[N], edge_cnt[N], node_cnt[N], first_val[N], second_val[N];

int find(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}
void merge(int u, int v)
{
    int root_u = find(u), root_v = find(v);
    if (root_u != root_v) {
        fa[root_u] = root_v;
        edge_cnt[root_v] += edge_cnt[root_u] + 1;
        node_cnt[root_v] += node_cnt[root_u];

        int temp[4] = { first_val[root_u], second_val[root_u], first_val[root_v], second_val[root_v] };
        sort(temp, temp + 4, greater<int>());
        first_val[root_v] = temp[0];
        second_val[root_v] = temp[1];
    } else
        edge_cnt[root_v]++;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> nums;
    vector<pair<int, int>> original;

    nums.reserve(2 * n);

    for (int i = 1; i <= 2 * n; i += 2) {
        int a, b;
        cin >> a >> b;
        nums.push_back(a);
        nums.push_back(b);
        original.push_back({ a, b });
    }
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    for (int i = 0; i < nums.size(); i++) {
        fa[i] = i;
        first_val[i] = nums[i];
        node_cnt[i] = 1;
        second_val[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        int u = lower_bound(nums.begin(), nums.end(), original[i].first) - nums.begin();
        int v = lower_bound(nums.begin(), nums.end(), original[i].second) - nums.begin();
        merge(u, v);
    }

    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (fa[i] == i) {
            if (edge_cnt[i] > node_cnt[i]) {
                cout << -1 << '\n';
                return 0;
            }
            if (edge_cnt[i] == node_cnt[i])
                ans = max(ans, first_val[i]);
            else
                ans = max(ans, second_val[i]);
        }
    }
    cout << ans << '\n';
    return 0;
}