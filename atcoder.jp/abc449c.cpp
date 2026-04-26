#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, l, r;
    cin >> n >> l >> r;

    vector<vector<int>> alphabet(26);
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        char c = s[i];
        alphabet[c - 'a'].push_back(i);
    }
    ll cnt = 0;
    for (int i = 0; i < 26; i++) {
        const vector<int>& vec = alphabet[i];
        int m = vec.size();
        for (int j = 0; j < m; j++) {
            const int pj = vec[j];
            int min_ = pj - r;
            int max_ = pj - l;
            if (max_ < 0)
                continue;
            auto it = lower_bound(vec.begin(), vec.begin() + j, min_);
            auto it2 = upper_bound(vec.begin(), vec.begin() + j, max_);
            cnt += (it2 - it);
        }
    }
    cout << cnt << '\n';
    return 0;
}