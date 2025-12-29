#include<bits/stdc++.h>

using namespace std;

int main() {
	string s, p;
    cin >> s >> p;
    int n = s.size(), m = p.size();
	int *nxt = new int [m + 5];
	nxt[0] = nxt[1] = 0;
	// 计算nxt数组
	for (int i = 1, j = 0; i < m; i++) {
		while (j > 0 && p[i] != p[j]) j = nxt[j - 1];
		if (p[i] == p[j]) j++;
		nxt[i] = j;
	}
	for (int i = 0, j = 0; i < n; i++) {
		while (j > 0 && s[i] != p[j]) j = nxt[j - 1];
		if (s[i] == p[j]) j++;
		if (j == m) {
			printf("%d\n", i - m + 2);
			j = nxt[j - 1];
		}
	}
    for (int i = 0; i < m; i++) {
        cout << nxt[i] << " ";
    }
	return 0;
}