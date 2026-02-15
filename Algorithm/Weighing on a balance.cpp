#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e6 + 5;

long long ans[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    long long x;
    cin >> x;

    int cnt = 0;
    while (x) {
        long long y = x / 3;
        int z = x % 3;
        ans[++cnt] = z;
        x = y;
    }
    for (int i = 1; i <= cnt; i++) {
        if (ans[i] == 3) {
            ans[i] = 0;
            ans[i + 1]++;
        } else if (ans[i] == 2) {
            ans[i + 1]++;
            ans[i] = -1;
        }
    }
    if(ans[cnt + 1])
        cnt++;
    cout << cnt << '\n';
    int index = 0;
    vector<int> right;
    for (int i = 1; i <= cnt; i++) {
        if (ans[i] == 1)
            cout << ans[i] * int(pow(3, index++)) << " ";
        else if (ans[i] == -1)
            right.push_back(ans[i] * -1 * int(pow(3, index++)));
        else
            index++;
    }
    cout << '\n';
    for (auto i : right) {
        cout << i << " ";
    }
    return 0;
}