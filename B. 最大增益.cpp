#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    char c, last;
    cin >> last;
    int s = 0;
    for (int i = 1; i < n; i++) {
        cin >> c;
        if (last != c) {
            s++;
        }
        last = c;
    }

    cout << n - 1 - s + (s % 2 && s / 2 < k) + min(s / 2, k) * 2;

    return 0;
}