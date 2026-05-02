#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    if (n % 2 == 0)
        cout << (n / 2 >= m ? "Yes" : "No") << '\n';
    else
        cout << (n / 2 + 1 >= m ? "Yes" : "No") << '\n';

    return 0;
}