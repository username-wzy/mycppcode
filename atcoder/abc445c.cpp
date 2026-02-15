#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1), f(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = n; i >= 1; i--) {
        if (a[i] == i)
            f[i] = i;   
        else
            f[i] = f[a[i]];
    }
    for (int i = 1; i <= n; i++)
        cout << f[i] << " ";
    return 0;
}
