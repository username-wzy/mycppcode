#include <bits/stdc++.h>
#define ll long long

using namespace std;

pair<int, int> expect_coach[100005];
int ans[100005], match[100005];
int now_volunteer[100005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> expect_coach[i].first >> expect_coach[i].second;
    }

    int cnt = 0;

    for (int i = n; i >= 1; i--) {
        int now = 1;
        int ii = i;

        while (now <= 2) {
            int p = (now == 1 ? expect_coach[ii].first
                              : expect_coach[ii].second);
            if (!match[p]) {
                match[p] = ii;
                now_volunteer[ii] = now;
                cnt++;
                break;
            } else if (match[p] > ii) {
                int last_stu = match[p];
                match[p] = ii;
                now_volunteer[ii] = now;
                ii = last_stu;
                now = now_volunteer[ii] + 1;
            } else {
                now++;
                if (now > 2)
                    break;
            }
        }

        ans[i] = cnt;
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}
