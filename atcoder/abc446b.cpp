#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    map<int, bool> vis;
    for (int i = 1; i <= n; i++) {
        int li;
        cin >> li;
        int choose = 0;
        bool flag = false;
        for (int j = 1; j <= li; j++) {
            int x;
            cin >> x;
            if (!vis[x] && !flag) {
                flag = true;
                vis[x] = true;
                choose = x;
                continue;
            }
        }
        cout << choose << '\n';
    }

    return 0;
}