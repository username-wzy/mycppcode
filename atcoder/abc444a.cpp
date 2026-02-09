#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    string s;
    cin >> s;
    bool flag = true;
    const int cs = s[0];
    for (int i = 1; i < s.size(); i++) {
        if (cs != s[i]) {
            flag = false;
        }
    }
    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T = 1; // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}