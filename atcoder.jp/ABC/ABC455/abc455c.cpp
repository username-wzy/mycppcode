#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

unordered_map<int, int> mp;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }

    vector<ll> new_a;

    for (auto it : mp) {
        new_a.push_back(it.second * 1LL * it.first);
    }

    sort(new_a.begin(), new_a.end(), greater<ll>());

    if (new_a.begin() + k >= new_a.end()) {
        cout << 0;
        return 0;
    }
    cout << accumulate(new_a.begin() + k, new_a.end(), 0LL);
    return 0;
}