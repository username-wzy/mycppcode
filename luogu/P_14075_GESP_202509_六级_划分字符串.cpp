#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5 + 5;

int a[N], dp[N];

void solve() {
    int n;
    string s;
    cin >> n >> s;
    // dp[i]表示从第一位到第i位可以的最大分数
    /*
        1. 独自成为1段 dp[i] = dp[i - 1] + a[1];
        2. 合并 ???
    */
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    s = ' ' + s;
    dp[1] = a[1];
    for (int i = 2; i <= n; i++) {
        // 用一个set判断有重复
        set<char> st;
        st.insert(s[i]);
        dp[i] = dp[i - 1] + a[1];
        for (int j = i - 1; j >= 1; j--) {
            if (st.count(s[j])) break;
            st.insert(s[j]);
            dp[i] = max(dp[i], dp[j - 1] + a[i - j + 1]);
        }
    }
    cout << dp[n];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // freopen("xxx.in", "r", stdin);
    // freopen("xxx.out", "w", stdout);

    int T = 1; // cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}