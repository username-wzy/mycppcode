#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unordered_map<string, int> mp;

    for (int i = 1; i <= n; i++) {
        string x;
        cin >> x;
        mp[x]++;
    }

    int ans = 52;

    for (auto [str, cnt] : mp) {
        ans--;
    }

    cout << ans;

    return 0;
}