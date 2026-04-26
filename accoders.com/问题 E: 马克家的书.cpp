#include <iostream>
#include <vector>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    int last = n, cnt = 0;
    for (int i = n; i >= 1; i--) {
        if (last == a[i]) 
            last--, cnt++;
    }
    std::cout << n - cnt << '\n';
}

int main() {
    int T = 1; std::cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}