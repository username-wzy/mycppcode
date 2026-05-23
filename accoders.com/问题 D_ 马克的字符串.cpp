#include <iostream>
#include <string>

int main()
{
    std::string s;
    std::cin >> s;
    int k;
    std::cin >> k;
    int n = s.size();
    s = " " + s;
    int ans = 0;
    for (int zx = 1; zx <= n; zx++) {
        int count = 0;
        for (int l = zx, r = zx; l >= 1 && r <= n; l--, r++) {
            count += (s[l] != s[r]);
            if (count > k)
                break;
            ans++;
        }
    }
    for (int zx = 1; zx < n; zx++) {
        int cnt = 0;
        for (int l = zx, r = zx + 1; l >= 1 && r <= n; l--, r++) {
            if (s[l] != s[r])
                cnt++;
            if (cnt > k)
                break;
            ans++;
        }
    }
    std::cout << ans;
    return 0;
}