#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll INF = 1e18;

vector<ll> len;
vector<vector<ll>> cnt;

string x, y;

ll get(int n, ll k, int c)
{
    if (k == 0)
        return 0;
    if (n == 1) {
        ll res = 0;
        for (int i = 0; i < min((ll)x.size(), k); i++) {
            if (x[i] - 'a' == c)
                res++;
        }
        return res;
    }
    if (n == 2) {
        ll res = 0;
        for (int i = 0; i < min((ll)y.size(), k); i++) {
            if (y[i] - 'a' == c)
                res++;
        }
        return res;
    }

    if (k <= len[n - 1]) {
        return get(n - 1, k, c);
    } else {
        return cnt[n - 1][c] + get(n - 2, k - len[n - 1], c);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> x >> y;

    len.push_back(0);
    len.push_back(x.size());
    len.push_back(y.size());

    cnt.push_back(vector<ll>(26, 0));
    cnt.push_back(vector<ll>(26, 0));
    cnt.push_back(vector<ll>(26, 0));

    for (char ch : x)
        cnt[1][ch - 'a']++;
    for (char ch : y)
        cnt[2][ch - 'a']++;

    int n = 2;
    while (len[n] < INF) {
        n++;
        len.push_back(min(INF, len[n - 1] + len[n - 2]));

        vector<ll> cur(26, 0);
        for (int i = 0; i < 26; i++) {
            cur[i] = cnt[n - 1][i] + cnt[n - 2][i];
            if (cur[i] > INF)
                cur[i] = INF;
        }
        cnt.push_back(cur);
    }

    int Q;
    cin >> Q;

    while (Q--) {
        ll L, R;
        char c;
        cin >> L >> R >> c;

        int id = c - 'a';

        ll ans = get(n, R, id) - get(n, L - 1, id);
        cout << ans << '\n';
    }

    return 0;
}