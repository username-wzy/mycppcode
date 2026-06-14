#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int max_ = 1e9;

pair<int, ll> pre[30];
ll pre10[11];
set<ll> st;

void dfs(ll val) // {val, len}
{
    if (val > max_)
        return;
    st.insert(val);
    for (int i = 0; i <= 29; i++) {
        ll nval = val * pre10[pre[i].first] + pre[i].second;
        dfs(nval);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i <= 29; i++) {
        pre[i].second = (1 << i);
        pre[i].first = to_string((1 << i)).size();
    }
    for (int i = 0; i <= 10; i++) {
        pre10[i] = pow(10, i);
    }
    for (int i = 0; i <= 29; i++) {
        dfs(pre[i].second);
    }
    int cnt = 0;
    for (int p : st) {
        if (++cnt == n) {
            cout << p;
            break;
        }
    }
    return 0;
}