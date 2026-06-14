#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x1, x2, y1, y2;
    cin >> x1 >> x2 >> y1 >> y2;
    int cnt = 0;
    for (int i = x1; i <= x2; i++) {
        if (i % 2 == 0) {
            // 选i到y1, 因为当(min(abs(i), y2) >= abs(y1)) 时i是最大的且是偶数
            cnt += min(abs(i), y2) - abs(y1) + 1;
        }
    }
    return 0;
}