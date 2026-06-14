#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

unordered_map<int, int> mp;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
        mp[s[i]]++;
    int max_freq = 0;
    for (auto [k, v] : mp) {
        if (v > max_freq) {
            max_freq = v;
        }
    }
    vector<char> max_freq_chars;
    for (auto [k, v] : mp) {
        if (v == max_freq) {
            max_freq_chars.push_back(k);
        }
    }
    for (char c : s) {
        if (find(max_freq_chars.begin(), max_freq_chars.end(), c) == max_freq_chars.end())
            cout << c;
    }

    return 0;
}