#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << '\n';
#define IAK std::ios::sync_with_stdio(false);
#define IOI std::cin.tie(nullptr)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<long, long>;

void solve()
{
    int x;
    cin >> x;
    priority_queue<int> a;
    priority_queue<int, vector<int>, greater<>> b;
    /*
        维护保证 |a| <= |b|，当总数为偶a.size == b.size，否则a.size == b.size + 1, a多装一个
    */

    a.push(x);
    int q;
    cin >> q;

    auto push = [&](int x) {
        if (x <= a.top())
            a.push(x);
        else
            b.push(x);

        if (a.size() > b.size() + 1) { // a至少比b大1以上也就是不符合a.size == b.size+1的条件
            int t = a.top();
            a.pop();
            b.push(t);
        } else if (a.size() < b.size()) {
            int t = b.top();
            b.pop();
            a.push(t);
        }
    };

    while (q--) {
        int x, y;
        cin >> x >> y;
        push(x), push(y);

        cout << a.top() << '\n';
    }
}

int main()
{
    IAK IOI;
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}