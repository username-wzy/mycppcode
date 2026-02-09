#include <bits/stdc++.h>

using namespace std;

unordered_map<int, char> mp = {
    { 10, 'A' },
    { 11, 'B' },
    { 12, 'C' },
    { 13, 'D' },
    { 14, 'E' },
    { 15, 'F' },
    { 16, 'G' },
    { 17, 'H' },
    { 18, 'I' },
    { 19, 'J' },
    { 20, 'K' },
};

int main()
{
    int n, k;
    cin >> n >> k;
    printf("%d=", n);
    vector<int> ans;
    while (n) {
        int div = n / k;
        int r = n - div * k;
        if (r < 0) {
            div++;
            r -= k;
        }
        ans.push_back(r);
        n = div;
    }
    for (int i = ans.size() - 1; i >= 0; i--) {
        if (ans[i] > 9) {
            cout << mp[ans[i]];
        } else
            cout << ans[i];
    }
    printf("(base%d)", k);
    return 0;
}