#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool isprime(int x)
{
    if (x < 2)
        return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0)
            return false;
    }
    return true;
}

int n, cnt = 0;
int a[30];
bool vis[30];

void dfs(int i)
{
    if (cnt >= 10)
        exit(0);
    if (i == n + 1) {
        cnt++;
        for (int i = 1; i <= n; i++) {
            cout << a[i] << " ";
        }
        cout << '\n';
        return;
    }
    for (int j = 2; j <= n; j++) {
        if (vis[j] || !isprime(j + a[i - 1]) || i == n && !isprime(j + 1)) {
            continue;
        }
        vis[j] = true;
        a[i] = j;
        dfs(i + 1);
        vis[j] = false;
        a[i] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    if (n % 2 != 0)
        return 0;

    a[1] = 1;

    dfs(2);

    return 0;
}