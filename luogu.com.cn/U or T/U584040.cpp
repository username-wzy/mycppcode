#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x;
    cin >> x;
    bool flag = false;
    if (x == 0) {
        cout << 0;
        return 0;
    }
    if (x < 0) {
        x *= -1;
        flag = true;
    }
    short ans[15432];
    int cnt = 0;
    while (x) {
        int y = x / 3;
        int z = x % 3;
        ans[++cnt] = z;
        x = y;
    }
    // for (int i = cnt; i >= 1; i--) {
    //     cerr << ans[i];
    // }
    for (int i = 1; i <= cnt; i++) {
        if (ans[i] == 3) {
            ans[i] = 0;
            ans[i + 1]++;
        } else if (ans[i] == 2) {
            ans[i + 1]++;
            ans[i] = -1;
        }
    }
    if (flag)
        for (int i = cnt + 1; i >= 1; i--) {
            if (i == cnt + 1 && ans[i] == 0)
                continue;
            if (ans[i] == -1)
                cout << '1';
            else if (ans[i] == 1)
                cout << 'Z';
            else
                cout << ans[i];
        }
        
    else
        for (int i = cnt + 1; i >= 1; i--) {
            if (i == cnt + 1 && ans[i] == 0)
                continue;
            if (ans[i] == -1)
                cout << 'Z';
            else
                cout << ans[i];
        }
    return 0;
}