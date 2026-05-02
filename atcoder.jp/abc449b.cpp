#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w;
    cin >> h >> w;

    int q;
    cin >> q;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int r;
            cin >> r;
            cout << w * r << '\n';
            h -= r;
        } else {
            int c;
            cin >> c;
            cout << h * c << '\n';
            w -= c;
        }
    }

    return 0;
}