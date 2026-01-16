#include <bits/stdc++.h>
#define ll long long

using namespace std;

string manacher(string& s)
{
    string t = "#";
    for (char ch : s) {
        t += ch, t += "#"; // 用#分割，使所有字符情况下
    }
    int M = 0, R = 0, n = t.size(); // 分别为对称中心点，和最大右边界
    int maxLen = 0, maxCenter = 0; // 最大长度与中心点
    vector<int> p(n, 0);
    for (int i = 0; i < n; i++) {
        int k = 2 * M - i; // 算对称点下标
        // 利用对称性快速算初始半径
        if (i < R) {
            p[i] = min(R - i, p[k]);
        }
        // 尝试扩展
        int l = i - (1 + p[i]), r = i + (1 + p[i]);
        while (l >= 0 && r < n && t[l] == t[r]) {
            p[i]++;
            l--, r++;
        }
        if (i + p[i] > R) {
            M = i, R = i + p[i];
        }
        // 记录最大值
        if (p[i] > maxLen)
            maxLen = p[i], maxCenter = i;
    }
    int start = (maxCenter - maxLen) / 2;
    return s.substr(start, maxLen);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string s;
    cin >> s;
    cout << manacher(s).size();

    return 0;
}