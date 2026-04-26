#include <bits/stdc++.h>
using namespace std;

bool check(long long L, int n, vector<long long>& a)
{
    int l = 1, r = n;
    while (l <= r) {
        if (a[r] == L) {
            // 这根没断
            r--;
        } else {
            if (l >= r || a[l] + a[r] != L)
                return false;
            l++;
            r--;
        }
    }
    return true;
};

int main()
{
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a.begin() + 1, a.end());
    long long mx = a[n];
    vector<long long> ans;
    // 情况 1：L = mx（最大那根没断）
    if (check(mx, n, a))
        ans.push_back(mx);

    // 情况 2：L = mx + a[i]，枚举不同的 a[i]
    for (int i = 1; i <= n; i++) {
        if (i > 1 && a[i] == a[i - 1])
            continue; // 去重
        long long L = mx + a[i];
        if (check(L, n, a))
            ans.push_back(L);
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
        if (i == 0 || ans[i] != ans[i - 1])
            cout << ans[i] << " ";
    cout << endl;
    return 0;
}
