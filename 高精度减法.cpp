#include <bits/stdc++.h>
#define ll long long

const int N = 1e5 + 5;

using namespace std;

int c[N], a[N], b[N];

void solve()
{
    string s, t;
    cin >> s >> t;
    if (s == t) {
        cout << 0;
        return;
    }
    if (s.size() < t.size() || s.size() == t.size() && s < t) {
        cout << '-';
        swap(s, t);
    }
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    for (int i = 0; i < s.size(); i++) {
        a[i + 1] = s[i] - '0';
    }
    for (int i = 0; i < t.size(); i++) {
        b[i + 1] = t[i] - '0';
    }
    for (int i = 1; i <= s.size(); i++) {
        c[i] = a[i] - b[i];
        if (c[i] < 0) {
            c[i] += 10;
            a[i + 1]--;
        }
    }
    int l = s.size();
    while (c[l] == 0)
        l--;
    for (int i = l; i >= 1; i--) {
        cout << c[i];
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