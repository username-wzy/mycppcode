#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;

    sort(arr.begin(), arr.end(), [](pii a, pii b) {
        return a.second > b.second;
    });

    vector<pair<int, int>> v;
    for (int i = 1; i <= n; i++) {
        if (v.size() == k)
            break;
        auto p = arr[i];
        int idx = p.first, delta = p.second;
        if (v.front().second == 0 && v.size() + 1 <= k) {
            v.push_back({ idx, delta });
        }
    }

    if (v.size() < k) {
    }
    for (int i = 1; i <= n; i++) {
        auto p = arr[i];
        int idx = p.first, delta = p.second;
        if (arr[idx].first == 0)
            continue;

        else {
        }
    }

    return 0;
