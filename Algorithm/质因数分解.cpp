#include<bits/stdc++.h>
#define ll long long

using namespace std;

map<int, int> mp;

void solve() {
	int n;
	cin >> n;
	string s = "n=";
	for (ll i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			n /= i;
			mp[i]++;
		}
	}
	if (n != 1) {
		mp[n]++;
	}
	for (auto p : mp) s += to_string(p.first) + '^' + to_string(p.second) + '*';
	for (int i = 0; i < s.size() - 1; i++) {
		cout << s[i];
	}
	cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // freopen("xxx.in", "r", stdin);
    // freopen("xxx.out", "w", stdout);

    int T = 1; // cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}
