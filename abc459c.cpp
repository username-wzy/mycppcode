#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct BIT {
    int n;
    vector<int> t;
    BIT(int n) : n(n), t(n + 1) {}
    void add(int pos, int delta) {
        for (; pos <= n; pos += pos & -pos) t[pos] += delta;
    }
    int sum(int pos) {
        int res = 0;
        for (pos = min(pos, n); pos > 0; pos -= pos & -pos) res += t[pos];
        return res;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    BIT bit(q + 5);
    vector<int> cnt(n + 1);
    vector<int> freq(q + 5);

    freq[0] = n;
    bit.add(1, n); // BIT position 1 = value 0

    int min_cnt = 0;
    int base = 0;

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;

            int old = cnt[x];
            cnt[x] = old + 1;

            freq[old]--;
            bit.add(old + 1, -1);
            freq[old + 1]++;
            bit.add(old + 2, 1);

            if (old == min_cnt && freq[old] == 0) {
                while (freq[min_cnt] == 0) min_cnt++;
            }

            while (min_cnt >= base + 1) base++;
        } else {
            int y;
            cin >> y;
            int threshold = base + y;
            if (threshold > q + 2) {
                cout << 0 << '\n';
            } else {
                cout << n - bit.sum(threshold) << '\n';
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
