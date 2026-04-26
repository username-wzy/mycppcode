#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int a[30];

void init()
{
    a[0] = 1;
    for (int i = 1; i <= 24; i++) {
        a[i] = (1 << i);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    cin >> x;

    init();

    vector<int> ans;
    for (int i = 24; i >= 1; i--) {
        if (x - a[i] >= 0) {
            x -= a[i];
            ans.push_back(a[i]);
        }
    }

    if (x) {
        cout << "-1";
        return 0;
    }

    for (int p : ans) {
        cout << p << " ";
    }

    return 0;
}