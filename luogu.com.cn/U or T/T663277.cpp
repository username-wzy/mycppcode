#include<bits/stdc++.h>
#define ll long long

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    ll n, m, k;
    cin >> n >> m >> k;
    m--;
    cout << (long long)((n - k > 0) ? n - k : 0) + (long long)(n * m);

    return 0;
}