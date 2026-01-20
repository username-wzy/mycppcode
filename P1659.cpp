#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e6 + 5;
const int MOD = 19930726;

int d[N];

ll qpow(ll a, ll b)
{
    ll sum = 1;
    while (b) {
        if (b & 1) {
            sum = a * sum % MOD;
        }
        b /= 2;
        a = a * a % MOD;
    }
    return sum;
}

vector<int> manacher(const string& s)
{
    const string& t = s;
    int M = 0, R = 0;
    const int n = t.size();
    int maxLen = 0, maxCenter = 0;

    vector<int> p(n, 0);

    for (int i = 0; i < n; i++) {
        int k = 2 * M - i;

        if (i < R) {
            p[i] = min(R - i, p[k]);
        }

        int l = i - (1 + p[i]), r = i + (1 + p[i]);
        while (l >= 0 && r < n && t[l] == t [r]) {
            p[i]++;
            l--, r++;
        }
  
        if (i + p[i] > R) {
            M = i, R = i + p[i];
        }

        if (p[i] > maxLen)
            maxLen = p[i], maxCenter = i;
    }
    for (auto& i : p) {
        i = i * 2 + 1;
    }
    return p;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> p = manacher(s);
    for (int i = 0; i < n; i++) {
        d[1]++, d[p[i] / 2 + 2]--;
    }
    map<ll, ll, greater<ll>> mp;
    for (int i = 1; i <= n; i++) {
        d[i] = d[i - 1] + d[i];
        // cout << d[i];
        mp[i * 2 - 1] = d[i];
    }
    ll sum = 1;
    for (auto i : mp) {
        sum = sum * qpow(i.first, min(i.second, k)) % MOD;
        k -= min(i.second, k);
        if (k == 0) {
            cout << sum;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
