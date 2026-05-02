#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;
std::vector<int> fa;

void init(int n)
{
    fa.resize(n + 1);
    for (int i = 1; i <= n; i++)
        fa[i] = i;
}

int find(int x)
{
    return (fa[x] == x ? x : fa[x] = find(fa[x]));
}

bool unite(int x, int y)
{
    int rootx = find(x), rooty = find(y);
    if (rootx == rooty) {
        return false;
    } else {
        fa[rootx] = rooty;
        return true;
    }
}

bool cmp(array<long long, 3>& a, array<long long, 3>& b)
{
    return a[2] < b[2];
}

long long kruskal(int n, std::vector<std::array<long long, 3>>& edge)
{
    std::sort(edge.begin(), edge.end(), cmp);
    long long w = 0, cnt = 0;
    for (auto p : edge) {
        if (unite(p[0], p[1])) {
            cnt++;
            w += p[2];
        }
        if (cnt == n - 1) {
            return w;
        }
    }
    return -1;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::array<long long, 3>> edge;
    for (int i = 0; i < m; i++) {
        long long x, y, z;
        std::cin >> x >> y >> z;
        edge.push_back({ x, y, z });
    }
    init(n);
    int x = kruskal(n, edge);
    if (x == -1) {
        std::cout << "orz";
    } else {
        std::cout << x;
    }
}