#include <bits/stdc++.h>
#define ll long long

using namespace std;
// D(n)=(n-1)(D(n-2)+D(n-1))
ll d[25];
int n;
ll dfs(int i)
{
    const ll di = ((n - 1) * (((d[i - 1] > 0) ? d[i - 1] : dfs(n - 1)) + ((d[i - 2] > 0) ? d[i - 2] : dfs(n - 2))));
    d[i] = di;
    return d[i];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;
    d[0] = 0;
    d[1] = 0;
    d[2] = 1;
    d[3] = 2;
    cout << dfs(n);
    return 0;
}