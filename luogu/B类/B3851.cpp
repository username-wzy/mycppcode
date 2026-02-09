#include <bits/stdc++.h>
using namespace std;

char dectohex(int x)
{
    return x < 10 ? char('0' + x) : char('A' + x - 10);
}

int main()
{
    int n;
    cin >> n;

    int g[25][25];
    unordered_map<int, int> freq;

    unordered_map<char, int> hextodec = {
        { '0', 0 },
        { '1', 1 },
        { '2', 2 },
        { '3', 3 },
        { '4', 4 },
        { '5', 5 },
        { '6', 6 },
        { '7', 7 },
        { '8', 8 },
        { '9', 9 },
        { 'A', 10 },
        { 'B', 11 },
        { 'C', 12 },
        { 'D', 13 },
        { 'E', 14 },
        { 'F', 15 }
    };

    int m = 0;

    // 读取图像
    for (int i = 0; i < n; i++) {
        string buf;
        cin >> buf;
        m = buf.size() / 2;
        for (int j = 0; j < m; j++) {
            char a = buf[2 * j];
            char b = buf[2 * j + 1];
            int val = hextodec[a] * 16 + hextodec[b];
            g[i][j] = val;
            freq[val]++;
        }
    }

    // 灰阶 + 次数
    vector<pair<int, int>> v;
    for (auto& p : freq)
        v.push_back(p);

    // 排序：次数降序，灰阶升序
    sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second != b.second)
            return a.second > b.second;
        return a.first < b.first;
    });

    // 选前 16 个
    vector<int> reps(16);
    for (int i = 0; i < 16; i++)
        reps[i] = v[i].first;

    // 灰阶 -> 编号
    unordered_map<int, int> id;
    for (int i = 0; i < 16; i++)
        id[reps[i]] = i;

    for (int i = 0; i < 16; i++) {
        cout << dectohex(reps[i] / 16) << dectohex(reps[i] % 16);
    }
    cout << '\n';

    // 压缩并输出图像
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int val = g[i][j];
            int best = 0;
            int bestd = abs(val - reps[0]);

            for (int k = 1; k < 16; k++) {
                const int d = abs(val - reps[k]);
                if (d < bestd) {
                    bestd = d;
                    best = k;
                }
            }
            cout << dectohex(best);
        }
        cout << '\n';
    }

    return 0;
}
