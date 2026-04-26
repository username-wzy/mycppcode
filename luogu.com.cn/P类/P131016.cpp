#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int up(int x)
{
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return (x / i);
        }
    }
    return 1; // if x is prime
}

int LCA(int x, int y)
{
    int cnt = 0;
    while (x != y) {
        if (x > y)
            x = up(x);
        else
            y = up(y);
        cnt++;
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        if (x == y)
            cout << "0\n";
        else
            cout << LCA(x, y) << '\n';
    }

    return 0;
}