/*
 * Z算法（扩展KMP，Extended KMP）
 *
 * Z算法是一种字符串匹配算法，用于快速求出一个字符串的Z函数。
 * Z函数定义：z[i] 表示字符串 s[i...n] 与 s[1...n-i+1] 的最长公共前缀长度。
 *
 * 应用场景：
 * - 判断一个字符串是否是另一个字符串的子串
 * - 求字符串的最长公共前缀
 * - 求字符串的最长 border（既是前缀又是后缀的子串）
 * - 字符串周期性分析
 *
 * 算法复杂度：O(n)，其中 n 为字符串长度
 *
 * 参考资料：
 * - OI Wiki: https://oi-wiki.org/string/z-func/
 * - 洛谷题解: https://www.luogu.com.cn/problem/solution/P5410
 */

#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // Z算法核心变量
    // [l, r] 表示当前最右的匹配区间，即 s[l...r] 与 s[1...r-l+1] 匹配
    int l = 1, r = 0;

    string s;
    cin >> s;

    // 在字符串前面加一个空格，使下标从1开始，方便处理
    s = ' ' + s;
    int n = s.size() - 1; // 字符串实际长度

    // z[i] 表示 s[i...n] 与 s[1...n-i+1] 的最长公共前缀长度
    int* z = new int[n + 5];

    // 从第2个位置开始计算Z值（因为 z[1] = n，即整个字符串与自己匹配）
    for (int i = 2; i <= n; i++) {
        // 如果当前位置i在当前最右匹配区间 [l, r] 内
        // 我们可以利用之前计算的信息来加速
        if (i <= r) {
            // k 是 i 在匹配区间 [l, r] 中对应的对称位置
            // 因为 s[i...r] 与 s[k...r-l+1] 匹配，所以 z[i] 至少为 z[k]
            int k = i - l + 1;
            // 取 z[k] 和剩余区间长度 r-i+1 的较小值
            // 这样可以避免超出区间范围
            z[i] = min(z[k], r - i + 1);
        }

        // 从当前已知的匹配长度开始，逐个字符向后扩展
        // 继续比较直到不匹配为止
        while (i + z[i] <= n && s[z[i] + 1] == s[i + z[i]])
            ++z[i];

        // 如果当前匹配区间比之前的更靠右，更新 l 和 r
        // 这样可以保证我们总是使用最右的匹配信息
        if (i + z[i] - 1 > r) {
            l = i, r = i + z[i] - 1;
        }
    }

    // 找出所有 Z 值中的最大值
    // 这个最大值表示字符串中最长的 border（既是前缀又是后缀的子串）长度
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, z[i]);
    }

    cout << ans;
    return 0;
}