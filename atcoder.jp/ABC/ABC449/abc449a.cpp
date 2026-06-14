#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long d;
    cin >> d;

    double pi = 3.14159265358979323846;
    printf("%.15lf\n", d / 4.0 * d * pi);

    return 0;
}