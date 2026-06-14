#include <bits/stdc++.h>
using namespace std;

vector<int> getCounts(const string& s) // 统计每个非A字符之间的A的数量
{
    vector<int> cnt;
    int c = 0;
    cnt.push_back(0);

    for (char ch : s) {
        if (ch == 'A')
            cnt.back()++;
        else
            cnt.push_back(0);
    }

    return cnt;
}

string get(const string& s) // 去掉所有A后的字符串
{
    string res;
    for (char c : s)
        if (c != 'A')
            res += c;
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;

    if (get(s) != get(t)) {
        cout << -1;
        return 0;
    }

    auto cs = getCounts(s);
    auto ct = getCounts(t);

    int ans = 0;

    for (int i = 0; i < cs.size(); i++)
        ans += abs(cs[i] - ct[i]);

    cout << ans;
}