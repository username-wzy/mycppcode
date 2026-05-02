#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    priority_queue<int, vector<int>, greater<int>> pq;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int h;
            cin >> h;
            pq.push(h);
        } else {
            int h;
            cin >> h;
            while (!pq.empty() && pq.top() <= h) {
                pq.pop();
            }
        }
        cout << pq.size() << '\n';
    }

    return 0;
}