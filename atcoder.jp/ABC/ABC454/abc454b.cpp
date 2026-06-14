#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    static int f[105];
    static int book[105];

    for (int i = 1; i <= n; i++) {
        cin >> f[i];
        book[f[i]]++;
    }

    bool fg1 = false;

    for (int i = 1; i <= m; i++) {
        if (book[i] > 1) {
            cout << "No\n";
            fg1 = true;
            break;
        }
    }
    if (!fg1) {
        cout << "Yes\n";
    }
    for (int i = 1; i <= m; i++) {
        if (book[i] == 0) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}