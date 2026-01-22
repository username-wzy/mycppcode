#include<bits/stdc++.h>
#define ll long long

using namespace std;

int v[105], nxt[105];

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		nxt[i] = i + 		1;
	}
	nxt[0] = 1, nxt[n] = -1; // 头为1，尾为-1
	int x, y;
	cin >> x >> y; //在x这个位置后插入一个y
	int p = 0; //从头找
	while (p != x) {
		p = nxt[p];
	}
	v[++n] = y	;
	nxt[n] = nxt[p]; // 新的节点的后继节点设置成p的后继节点
	nxt[p] = n; // p的后继节点设置为新的节点
	p = 0; // 从头遍历
	cout << p << " "; // 输出头
	for (int i = 0; i <= n; i++) { // 输出整个链表
		cout << v[nxt[p]] << " ";
		p = nxt[p];
	}
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
