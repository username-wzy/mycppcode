#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c;
    cin >> a >> b >> c;

    if (a != b && b == c)
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}