#include<bits/stdc++.h>
#define ll long long

using namespace std;
int n, ans, m, trie[205][26], idx = 0;
string s;
bool dp[1100000], cnt[205];

void insert() {
    int p = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        int x = s[i] - 'a';
        if (!trie[p][x]) trie[p][x] = ++idx;
        p = trie[p][x];
    }
    cnt[p] = 1;
}

void solve() {
    cin >> n >> m;
    while (n--) {
        cin >> s;
        insert();
    }
    // for (int i = 0; i <= 25; i++) {
    //     for (int j = 0; j <26; j++) {
    //         cerr << trie[i][j];
    //     }
    //     cerr << '\n';
    // }
    while(m--) {
        memset(dp,0, sizeof dp);
        ans = 0;
        dp[0] = 1;
        cin >> s;
        s = ' ' + s;
        for (int i = 1; i < int(s.size()) && i <= ans + 10; i++) {
            int j = i, p = 0;
            while (j && i - j + 1 <= 10) {
                int x = s[j] - 'a';
                // cout<<"dog";
                // cout<<p<<" "<<x<<" "<<trie[p][x]<<endl;
                if (!trie[p][x]) break;
                // cout<<"dog";
                p = trie[p][x];
                if (cnt[p] && dp[j - 1]) {
                    dp[i] = 1;
                    ans = i;
                }
                j--;
            }
        }
        cout << ans << '\n';
    }
}

int main() {
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