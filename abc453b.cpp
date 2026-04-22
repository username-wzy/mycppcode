#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, x;
    cin >> t >> x;

    int a0;
    cin >> a0;

    cout << 0 << " " << a0 << "\n";

    for (int i = 1; i <= t; i++) {
        int ai;
        cin >> ai;
        if (abs(ai - a0) >= x) {
            cout << i << " " << ai << "\n";
            a0 = ai;
        }
    }

    return 0;
}