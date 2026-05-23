#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << '\n';
#define IAK std::ios::sync_with_stdio(false);
#define IOI std::cin.tie(nullptr)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<long, long>;

void solve()
{
    int n;
    cin >> n;
    const vector<string> needfind = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        char head = s[0];
        for (int i = 0; i < 8; i++) {
            if (needfind[i].find(head) != string::npos) {
                cout << i + 2;
                break;
            }
        }
    }
}

int main()
{
    IAK IOI;
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}