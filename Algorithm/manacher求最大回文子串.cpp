/*
 * Manacher算法（马拉车算法）
 *
 * Manacher算法是一种用于在线性时间内找出字符串中最长回文子串的算法。
 * 传统暴力枚举中心点的方法时间复杂度为O(n²)，而Manacher算法通过利用回文串的对称性，
 * 将时间复杂度优化到O(n)。
 *
 * 核心思想：
 * 1. 预处理字符串：在字符之间插入特殊字符（如#），使所有回文子串都变成奇数长度
 * 2. 维护最右回文边界：记录当前已知的回文子串的最右边界R及其中心M
 * 3. 利用对称性：对于当前位置i，如果i在当前最右回文边界内，可以利用对称点的回文半径信息
 * 4. 向外扩展：在利用对称信息的基础上，继续向外扩展以找到最大的回文半径
 *
 * 应用场景：
 * - 求字符串的最长回文子串
 * - 统计字符串中所有回文子串的数量
 * - 回文串相关的问题
 *
 * 算法复杂度：O(n)，其中 n 为字符串长度
 *
 * 参考资料：
 * - OI Wiki: https://oi-wiki.org/string/manacher/
 * - 洛谷题解: https://www.luogu.com.cn/problem/solution/P3805
 */

#include <bits/stdc++.h>
#define ll long long

using namespace std;

// Manacher算法实现：返回字符串s的最长回文子串
string manacher(string& s)
{
    // 预处理：在字符之间插入#，使所有回文子串都变成奇数长度
    // 例如："aba" -> "#a#b#a#"
    string t = "#";
    for (char ch : s) {
        t += ch, t += "#";
    }

    // M: 当前最右回文子串的中心位置
    // R: 当前最右回文子串的右边界（不包含）
    int M = 0, R = 0, n = t.size();

    // maxLen: 最长回文子串的半径长度
    // maxCenter: 最长回文子串的中心位置
    int maxLen = 0, maxCenter = 0;

    // p[i]: 以位置i为中心的回文子串的半径长度
    vector<int> p(n, 0);

    for (int i = 0; i < n; i++) {
        // 计算i关于M的对称点k的位置
        int k = 2 * M - i;

        // 如果i在当前最右回文边界R内，利用对称性快速计算初始半径
        // 取对称点的半径和到R的距离的最小值，避免超出边界
        if (i < R) {
            p[i] = min(R - i, p[k]);
        }

        // 尝试向外扩展回文子串
        // 从当前已知半径的下一个位置开始比较
        int l = i - (1 + p[i]), r = i + (1 + p[i]);
        while (l >= 0 && r < n && t[l] == t[r]) {
            p[i]++; // 扩展成功，半径+1
            l--, r++; // 继续向外扩展
        }

        // 如果当前回文子串超过了最右边界R，更新M和R
        if (i + p[i] > R)
            M = i, R = i + p[i];

        // 记录最大回文子串的信息
        if (p[i] > maxLen)
            maxLen = p[i], maxCenter = i;
    }

    // 计算最长回文子串在原字符串中的起始位置
    // 在预处理后的字符串中，原字符串的字符下标都是偶数位置
    // 所以需要除以2来转换回原字符串的下标
    int start = (maxCenter - maxLen) / 2;
    return s.substr(start, maxLen);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string s;
    cin >> s;

    // 输出最长回文子串的长度
    cout << manacher(s).size();

    return 0;
}