/*
test case 1
56 12 1 99 1000 234 33 55 99 812

sorted:
1 12 33 55 56 99 99 234 812 1000
*/

#include <algorithm>
#include <iostream>
#include <iomanip>

const int N = 1005;

class person {
public:
    int id, time;
};

int n;
person a[N];

int main()
{
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i].time;
        a[i].id = i;
    }
    std::stable_sort(a + 1, a + 1 + n, [](const person& a, const person& b) {
        return a.time < b.time;
    });
    long long res = 0;
    for (int i = 1; i <= n; i++)
        res += a[i].time * (n - i);
    for (int i = 1; i <= n; i++)
        std::cout << a[i].id << ' ';
    std::cout << '\n' << std::fixed << std::setprecision(2) << static_cast<double>(res) / n;
    return 0;
}