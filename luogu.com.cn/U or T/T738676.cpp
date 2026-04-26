#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int maxLOG = 60;

bool hws(long long x)
{
    string s = to_string(x);
    string t = s;
    reverse(t.begin(), t.end());
    return (s == t);
}

void solve()
{
    long long n;
    cin >> n;
    for (long long i = maxLOG; i >= 0; i--) {
        if ((1 << i) <= n) {
            if (hws(n - (1 << i))) {
                cout << "Yes\n";
                return;
            }
        }
    }
    cout << "No\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}