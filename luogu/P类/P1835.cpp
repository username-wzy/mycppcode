#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool ok[1000005], isnt_prime[1000005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int l, r;
    cin >> l >> r;
    vector<int> primes;
    isnt_prime[0] = isnt_prime[1] = 1;
    for (int i = 2; i <= 50005; i++) {
        if (!isnt_prime[i])
            primes.push_back(i);
        for (int j = 0; j < primes.size() && i * primes[j] <= 50005; j++) {
            isnt_prime[i * primes[j]] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
    for (int p : primes) {
        ll start = (l + p - 1) / p * p;
        if (start == p)
            start += p;
        for (ll j = start; j <= r; j += p) {
            ok[j - l] = true;
        }
    }
    int cnt = 0;
    for (int i = 0; i < r - l + 1; i++) {
        cnt += (!ok[i]);
    }
    if (l == 1)
        cnt--;
    cout << cnt;
    return 0;
}