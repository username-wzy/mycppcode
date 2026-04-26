#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    string s[105];
    int n, m = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        m = max(m, (int)s[i].size());
    }
    for (int i = 0; i < n; i++) {
        const int len = s[i].size();
        const int padding = (m - len) / 2;
        for (int i = 0; i < padding; i++)
            cout << '.';
        for (int j = 0; j < len; j++)
            cout << s[i][j];
        for (int i = 0; i < padding; i++)
            cout << '.';
        cout << "\n";
    }
    return 0;
}