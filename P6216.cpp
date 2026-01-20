#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 3e6 + 5;

int s[N], ss[N];

vector<int> manacher(string& s)
{
    string t = "#";
    for (char ch : s) {
        t += ch, t += "#";
    }
    int M = 0, R = 0, n = t.size();
    vector<int> p(n, 0);
    for (int i = 0; i < n; i++) {
        int k = 2 * M - i;
        if (i < R) {
            p[i] = min(R - i, p[k]);
        }
        int l = i - (1 + p[i]), r = i + (1 + p[i]);
        while (l >= 0 && r < n && t[l] == t[r]) {
            p[i]++;
            l--, r++;
        }
        if (i + p[i] > R) {
            M = i, R = i + p[i];
        }
    }
    return p;
}

vector<int> kmp(string& s, string& t)
{
    const int n = s.size(), m = t.size();
    vector<int> nxt(m + 5, 0), wonderful(n + 5, 0);
    for (int i = 1, j = 0; i < m; i++) {
        while (j > 0 && t[i] != t[j])
            j = nxt[j - 1];
        if (t[i] == t[j])
            j++;
        nxt[i] = j;
    }
    for (int i = 0, j = 0; i < n; i++) {
        while (j > 0 && s[i] != t[j])
            j = nxt[j - 1];
        if (s[i] == t[j])
            j++;
        if (j == m) {
            wonderful[i - m + 1]++;
            j = nxt[j - 1];
        }
    }
    return wonderful;
}

void solve()
{
    // faker 0-based, wonderful 0-based
    int n, m;
    string a, b;
    cin >> n >> m >> a >> b;
    vector<int> faker = kmp(a, b);
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + faker[i - 1];
    for (int i = 1; i <= n; i++)
        ss[i] = ss[i - 1] + s[i];
    vector<int> p = manacher(a);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (2 * p[i - 1] - 1 < m)
            continue;
        int r = i + p[i - 1] - 1, l = i - p[i - 1] + 1;
        l--;
        r = r - m + 1;
        int mid = (l + r) >> 1;
        ans += (faker[r] - faker[mid] - faker[((l + r) & 1) ? mid - 1 : mid - 2] + faker[l - 2]);
    }
    cout << ans;
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