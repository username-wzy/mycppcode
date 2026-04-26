#include <bits/stdc++.h>
#define ll long long

constexpr int N = 1e6 + 10;
short a[N] = {}, b[N] = {}, c[N] = {};

std::string jia(std::string s, std::string t) {
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    for (int i = 0; i < s.size(); i++)
        a[1 + i] = s[s.size() - 1 - i] - '0';
    for (int i = 0; i < t.size(); i++)
        b[1 + i] = t[t.size() - 1 - i] - '0';
    
    a[0] = s.size();
    b[0] = t.size();
    
    int maxn = std::max(a[0], b[0]);
    short jw = 0;
    for (int i = 1; i <= maxn; i++) {
        c[i] = (a[i] + b[i] + jw) % 10;
        jw = (a[i] + b[i] + jw) / 10;
    }
    if (jw > 0) c[++maxn] = jw;
    c[0] = maxn;
    
    while (c[c[0]] == 0 && c[0] > 1) c[0]--;
    
    std::string res;
    for (int i = c[0]; i >= 1; i--)
        res = res + char(c[i] + '0');
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n;
    std::cin >> n;
    if (n < 3) {
        std::cout << n;
        return ;
    }
    std::string f1 = "1", f2 = "2", f3 = "";
    for (int i = 3; i <= n; i++) {
        f3 = jia(f1, f2);
        f1 = f2;
        f2 = f3;
    }
    std::cout << f3;
}