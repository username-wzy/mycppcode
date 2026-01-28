#include <iostream>
using namespace std;

const int MAX_N = 100005; // n的最大值 + 5，用于学生相关数组
const int MAX_M = 100005; // m的最大值 + 5，用于教练相关数组

int main()
{
    int n, m;
    cin >> n >> m;

    // 使用常量定义的数组
    int a[MAX_N]; // a[1]~a[n] 存储第一选择
    int b[MAX_N]; // b[1]~b[n] 存储第二选择

    // 读取输入数据
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
    }

    // 教练匹配数组和答案数组
    int coach_match[MAX_M] = { 0 }; // 初始化为0，表示教练空闲
    int ans[MAX_N] = { 0 }; // 初始化为0，ans[i]表示从i到n能成功的学生数

    // 从后往前处理每个学生
    for (int i = n; i >= 1; --i) {
        int c = a[i]; // 学生 i 的第一选择

        if (coach_match[c] == 0) {
            // 教练 c 空闲，直接占用
            coach_match[c] = i;
            ans[i] = ans[i + 1] + 1; // 成功人数加1
        } else {
            int j = coach_match[c]; // 当前占用教练 c 的学生 j
            int d = b[j]; // 学生 j 的第二选择

            if (coach_match[d] == 0) {
                // 教练 d 空闲，学生 j 调整到 d，学生 i 占用 c
                coach_match[d] = j;
                coach_match[c] = i;
                ans[i] = ans[i + 1] + 1; // 成功人数加1
            } else {
                // 教练 d 已被占用，学生 j 调整失败，学生 i 占用 c
                coach_match[c] = i;
                ans[i] = ans[i + 1]; // 成功人数不变
            }
        }
    }

    // 输出结果
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << endl;
    }

    return 0;
}
