#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string s;
    cin >> s;
    int idx = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != 'o') {
            idx = i;
            break;
        }
    }
    if (s[idx] == 'o') {
        idx = s.size();
    }
    for (int i = idx; i < s.size(); i++) {
        cout << s[i];
    }

    return 0;
}