#include <bits/stdc++.h>

using namespace std;

int main()
{
    const char tohex[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
    long long x;
    cin >> x;
    const int th7 = 128;
    do {
        int y = x % th7;
        x /= th7;
        if (x)
            y += th7;
        cout << tohex[y / 16] << tohex[y % 16] << " ";
    } while (x);
    return 0;
}