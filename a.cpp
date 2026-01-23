#include <algorithm>
#include <array>
#include <iostream>
using namespace std;
const int N = 1000000 + 10;
array<array<int, 2>, N> student;
array<int, N> choose;
array<int, N> pos;
array<int, N> res;
int cnt;
int n;
int m;
void fun(int i)
{
    int p = 1;
    while (p <= 2) {
        int c = student[i][p - 1];
        if (choose[c] == 0) {
            choose[c] = i;
            pos[i] = p;
            cnt++;
            return;
        } else if (choose[c] > i) {
            int oldStudent = choose[c];
            choose[c] = i;
            pos[i] = p;
            i = oldStudent;
            p = pos[i] + 1;
        } else {
            p++;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> student[i][0] >> student[i][1];
    }
    for (int i = n; i >= 1; i--) {
        fun(i);
        res[i] = cnt;
    }
    for (int i = 1; i <= n; i++) {
        cout << res[i] << '\n';
    }
    return 0;
}