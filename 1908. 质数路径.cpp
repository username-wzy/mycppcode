#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool vis[10005];

int main()
{
    vector<int> primes;
    for (int i = 2; i <= 9999; i++) {
        if (!vis[i])
            primes.push_back(i);
        for (int j = 0; j < (int)primes.size() && primes[j] * i <= 9999; j++) {
            vis[i * primes[j]] = true;
            if (i % primes[j] == 0)
                break;
        }
    }

    int n;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;

        queue<pair<int, int>> q;
        q.push({ a, 0 });

        bool used[10005] = { false };
        used[a] = true;
        bool found = false;

        while (!q.empty()) {
            pair<int, int> u = q.front();
            q.pop();

            if (u.first == b) {
                cout << u.second << '\n';
                found = true;
                break;
            }

            int digits[4];
            int temp = u.first;
            digits[0] = temp / 1000; // 千位
            digits[1] = (temp / 100) % 10; // 百位
            digits[2] = (temp / 10) % 10; // 十位
            digits[3] = temp % 10; // 个位

            for (int i = 0; i < 4; i++) {
                int old_digit = digits[i];
                for (int d = 0; d <= 9; d++) {
                    if (d == old_digit)
                        continue; // 跳过本身
                    if (i == 0 && d == 0)
                        continue; // 第一位不能为0

                    digits[i] = d;
                    int next_num = digits[0] * 1000 + digits[1] * 100 + digits[2] * 10 + digits[3];

                    // 如果是质数且未访问
                    if (!vis[next_num] && !used[next_num]) {
                        used[next_num] = true;
                        q.push({ next_num, u.second + 1 });
                    }
                }
                digits[i] = old_digit; // 还原，准备修改下一位
            }
        }

        if (!found) {
            cout << "Impossible" << '\n';
        }
    }

    return 0;
}