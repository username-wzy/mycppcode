#include <bits/stdc++.h>
#define ll long long

using namespace std;

int c[200005];

void solve()
{
    string a, b;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            c[i + j] += (a[i] - '0') * (b[j] - '0');
        }
    }
    int jw = 0;
    string ans;
    for (int i = 0; i < a.size() + b.size(); i++) {
        ans.push_back((c[i] + jw) % 10 + '0');
        jw = (c[i] + jw) / 10;
    }
    if (jw)
        ans.push_back(jw + '0');
    reverse(ans.begin(), ans.end());
    int l = 0;
    while (l < ans.size() - 1 && ans[l] == '0') {
        l++;
    }
    for (int i = l; i < ans.size(); i++) {
        cout << ans[i];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // freopen("xxx.in", "r", stdin);
    // freopen("xxx.out", "w", stdout);

    int T = 1; // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}