#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int h1, m1, h2, m2;
    cin >> h1 >> m1 >> h2 >> m2;
    h1 *= 60, h2 *= 60;
    cout << h2 + m2 - h1 - m1;
    return 0;
}