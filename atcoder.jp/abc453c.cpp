#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

double l[25];
int n;
int ans = 0;

void dfs(int i, int current_ans, double k)
{
    if (i > n) {
        ans = max(ans, current_ans);
        return;
    }

    // 选择一：加 l[i]
    double next_k_plus = k + l[i];
    int cross_plus = ((k > 0 && next_k_plus < 0) || (k < 0 && next_k_plus > 0)) ? 1 : 0;
    dfs(i + 1, current_ans + cross_plus, next_k_plus);

    // 选择二：减 l[i]
    double next_k_minus = k - l[i];
    int cross_minus = ((k > 0 && next_k_minus < 0) || (k < 0 && next_k_minus > 0)) ? 1 : 0;
    dfs(i + 1, current_ans + cross_minus, next_k_minus);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> l[i];
    }

    dfs(1, 0, 0.5);
    cout << ans;

    return 0;
}