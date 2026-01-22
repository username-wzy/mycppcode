#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> res; // 存储除法结果的每一位数字

void solve()
{
    string a; // 被除数，以字符串形式输入以支持大数
    int b, m; // b是除数，m是需要保留的小数位数
    cin >> a >> b >> m;
    int r = 0; // 余数，初始为0

    // 第一步：计算整数部分的除法
    // 逐位处理被除数的每一位
    for (auto ch : a) {
        r = r * 10 + (ch - '0'); // 更新余数：当前余数*10 + 当前位数字
        res.push_back(r / b); // 将当前位的商存入结果数组
        r %= b; // 更新余数为当前位除以除数的余数
    }

    size_t q = res.size() - 1; // 记录整数部分的最后一位位置（用于后面添加小数点）

    // 第二步：计算小数部分，多计算一位用于四舍五入
    for (int i = 0; i <= m; i++) {
        r *= 10; // 余数乘以10，继续计算下一位小数
        res.push_back(r / b); // 将小数位的商存入结果数组
        r %= b; // 更新余数
    }

    // 第三步：四舍五入处理
    // 检查最后一位（多计算的那位）是否大于等于5
    if (res[res.size() - 1] >= 5) {
        res[res.size() - 2]++; // 前一位加1
        // 处理进位：从后往前检查是否有需要进位的情况
        for (size_t i = res.size() - 2; i >= 0; i--) {
            if (res[i] >= 10) {
                res[i - 1]++; // 前一位加1
                res[i] = 0; // 当前位归0
            } else {
                break; // 无需继续进位，退出循环
            }
        }
    }

    // 第四步：去除前导零并输出结果
    int l = 0;
    // 找到第一个非零的位置（但保留至少一位数字）
    while (l < res.size() - 1 && res[l] == 0)
        l++;
    res.pop_back(); // 丢掉第m+1为小数
    // 输出结果，在整数部分和小数部分之间添加小数点
    for (size_t i = l; i < res.size(); i++) {
        cout << res[i];
        // 当输出到整数部分最后一位时，添加小数点
        if (i == q)
            cout << '.';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T = 1; // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}