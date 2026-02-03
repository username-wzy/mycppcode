#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

int n;
int in[30];
std::unordered_map<char, bool> mp;
bool edge[30][30];
std::string s[50005];
std::vector<int> g[30];

std::vector<int> ans;

void toposort()
{
    std::queue<int> q;
    for (int i = 1; i <= 26; i++) {
        if (!in[i] && mp['A' + i - 1])
            q.push(i);
    }
    int cnt = 0;
    while (!q.empty()) {
        cnt++;
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for (int v : g[u]) {
            if (--in[v] == 0)
                q.push(v);
        }
    }
    if (ans.size() < cnt) {
        std::cout << 0 << '\n';
        exit(0);
    }
}

int main()
{
    std::cin >> n;
    std::cin >> s[1];
    for (auto i : s[1]) {
        mp[i] = 1;
    }
    for (int i = 2; i <= n; i++) {
        std::cin >> s[i];
        for (auto i : s[i]) {
            mp[i] = 1;
        }
        int p = 0;
        while (p < std::min(s[i - 1].size(), s[i].size()) && s[i - 1][p] == s[i][p])
            p++; // 判断第一个字母不相同位置
        if (p == std::min(s[i - 1].size(), s[i].size())) {
            if (s[i - 1].size() > s[i].size()) {
                std::cout << 0;
                return 0;
            }
            continue; // 合法前缀，无信息
        }
        int u = s[i - 1][p] - 'a' + 1;
        int v = s[i][p] - 'a' + 1;
        if (!edge[u][v]) {
            edge[u][v] = true;
            g[u].push_back(v);
            in[v]++;
        }
    }
    std::cin >> s[n + 1];
    for (int i = 0; i < s[n + 1].size(); i++) {
        mp[s[n + 1][i]] = 1;
    }
    toposort();
    for (int x : ans) {
        std::cout << static_cast<char>(x - 1 + 'a');
    }
    return 0;
}