#include <bits/stdc++.h>
#define ll long long

using namespace std;

/**
 * Z函数算法：计算字符串s的Z数组
 * Z[i]表示从位置i开始的子串与s的最长公共前缀长度
 */
vector<int> getZ(string& s, int& n)
{
    int l = 0, r = 0; // 维护最右Z-box区间[l,r]
    const int ns = s.size();
    vector<int> z(ns, 0);

    // 计算z[1]
    while (1 + z[1] < ns && s[z[1]] == s[1 + z[1]])
        z[1]++;
    if (z[1] > 0)
        l = 1, r = z[1];

    // 计算z[2..n-1]
    for (int i = 2; i < ns; i++) {
        if (i <= r) {
            // i在当前Z-box内，可以利用已计算的信息
            int k = i - l; // 对称位置
            z[i] = min(z[k], r - i + 1);
        }
        // 尝试扩展匹配
        while (i + z[i] < ns && s[z[i]] == s[i + z[i]])
            z[i]++;
        // 更新最右Z-box
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }

    // 输出Z数组用于调试
    for (int i = 1; i < ns; i++)
        cerr << z[i] << " ";
    cerr << endl;

    return z;
}
void patternMatching(string s, string t)
{
    // 构造新串：t + "#" + s
    string combined = t + "#" + s;
    int n = combined.size();
    auto z = getZ(combined, n);

    cout << "模式串 '" << t << "' 在文本串 '" << s << "' 中的出现位置: ";
    for (int i = t.size() + 1; i < n; i++) {
        if (z[i] == t.size()) {
            cout << i - t.size() - 1 << " "; // 转换为原文本串中的位置
        }
    }
    cout << endl;
}

void solve()
{
    string s, t;
    cin >> s >> t;
    int n = s.size();
    auto z = getZ(s, n);

    patternMatching(s, t);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // freopen("xxx.in", "r", stdin);
    // freopen("xxx.out", "w", stdout);

    int T = 1; // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}