#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    int cnt = 0;

    if (!(cin >> n >> k))
        return 0;

    vector<pii> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;

    sort(a.begin(), a.end(), [](pii a, pii b) {
        return a.second > b.second;
    });

    priority_queue<pii, vector<pii>, greater<pii>> q;
    unordered_map<int, int> mp;

    int cnt = 0;

    for (int i = 0; i < n; i++) {
        ll idx = a[i].first, p = a[i].second;
        if (mp.find(idx) == mp.end() && cnt < k) {
            mp[idx]++;
            q.push({ p, idx });
            cnt++;
            a[i].second = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        ll idx = a[i].first, p = a[i].second;
        if (cnt < k) {
            mp[idx]++;
            q.push({ p, idx });
            cnt++;
        } else {
            if (mp.find(idx) == mp.end())
                continue;
            ll p2 = q.top().first, idx2 = q.top().second;
            int s = mp.size();
            if (mp[idx] == 1) {
                if (p + (s - 1) * (s - 1) > p2 + s * s) {
                    q.pop();
                    mp[idx2]++;
                    mp[idx]--;
                    mp.erase(mp.find(idx2));
                    q.push({ p, idx });
                }
            }
        }
    }
    ll sum = mp.size() * mp.size();

    while (!q.empty()) {
        sum += q.top().first;
        q.pop();
    }

    cout << sum;
    return 0;
}