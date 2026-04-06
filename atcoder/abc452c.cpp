#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool ok[15][15][30]; // ok[len][idx][char] 表示长度为len，在idx位置上字符为char的字符串是否可以成为鱼刺

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }
    int m;
    cin >> m;
    vector<string> s(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> s[i];
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < s[i].size(); j++) {
            ok[s[i].size()][j + 1][s[i][j] - 'a'] = true;
        }
    }
    for (int i = 1; i <= m; i++) {
        if (s[i].size() != n) {
            cout << "No\n";
            continue;
        }
        bool okk = true;
        for (int j = 1; j <= n; j++) {
            if (!ok[a[j]][b[j]][s[i][j - 1] - 'a']) {
                cout << "No\n";
                okk = false;
                break;
            }
        }
        if (okk)
            cout << "Yes\n";
    }
    return 0;
}