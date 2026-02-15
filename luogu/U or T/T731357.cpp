#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int cnt_0 = 0;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 0)
                cnt_0++;
        }
        
        if (n == 1) {
            cout << (a[0] == 0 ? "Alice" : "Bob") << "\n";
        } else if (n == 2) {
            cout << (cnt_0 == 0 ? "Alice" : "Bob") << "\n";
        } else {
            cout << (cnt_0 == n ? "Bob" : "Alice") << "\n";
        }
    }
    return 0;
}
