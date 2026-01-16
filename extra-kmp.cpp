#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int l = 1, r = 0;
    string s;
    cin >> s;
    s = ' ' + s;
    int n = s.size() - 1;
    int* z = new int[n + 5];
    for (int i = 2; i <= n; i++) {
        if (i <= r) {
            int k = i - l + 1;
            z[i] = min(z[k], r - i + 1);
        }
        while (i + z[i] <= n && s[z[i] + 1] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r) {
            l = i, r = i + z[i] - 1;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, z[i]);
    }
    cout << ans;
    return 0;
}