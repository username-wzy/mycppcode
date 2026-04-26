#include <bits/stdc++.h>

using namespace std;

int w[10][10];
int dp[1024];

void solve()
{
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    memset(w, 0, sizeof(w));
    vector<int> all_char_s;
    bool vis[10] = { false };
    for (int i = 0; i < n; ++i) {
        int digit_s = s[i] - '0';
        int digit_t = t[i] - '0';
        w[digit_s][digit_t]++;
        if (!vis[digit_s]) {
            vis[digit_s] = true;
            all_char_s.push_back(digit_s);
        }
    }

    for (char c : all_char_s) {
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
        solve();

    return 0;
}