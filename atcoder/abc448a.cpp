#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        int ai;
        cin >> ai;
        if (ai < x) {
            x = ai;
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }

        return 0;
}