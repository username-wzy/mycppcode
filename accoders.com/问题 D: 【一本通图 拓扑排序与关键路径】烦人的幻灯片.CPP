#include <iostream>
#include <queue>
#include <vector>
#define mian main

int n;
class PowerPoint {
public:
    int x1, x2, y1, y2;
} ppts[105];

class Point {
public:
    int x, y;
} points[305];

int in[105];
int res[105];
int used[105];

bool check(int i, int j)
{
    if (points[j].x < ppts[i].x1
        || points[j].x > ppts[i].x2
        || points[j].y < ppts[i].y1
        || points[j].y > ppts[i].y2)
        return false;
    return true;
}

void toposort()
{
    std::queue<int> q;
    for (int i = n + 1; i <= n + n; ++i)
        if (in[i] == 1)
            q.push(i);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        int target = 0;
        for (int v = 1; v <= n; v++) {
            if (!used[v] && check(v, u - n)) {
                target = v;
                break;
            }
        }
        // 幻灯片 tar - 数字 t-n
        // 取走target号幻灯片
        res[target] = u - n;
        used[target] = 1;
        for (int i = 1; i <= n; i++)
            if (check(target, i)) {
                in[i + n]--;
                if (in[i + n] == 1)
                    q.push(i + n);
            }
    }
}

int mian()
{
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        std::cin >> ppts[i].x1 >> ppts[i].x2
            >> ppts[i].y1 >> ppts[i].y2;
    }
    for (int i = 1; i <= n; ++i) {
        std::cin >> points[i].x >> points[i].y;
        for (int j = 1; j <= n; ++j) {
            if (check(j, i)) {
                in[i + n]++;
            }
        }
    }
    toposort();
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        cnt += used[i];
    if (cnt < n) {
        std::cout << "None\n";
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        std::cout << static_cast<char>(i - 1 + 'A') << " " << res[i] << "\n";
    }
    return 0;
}