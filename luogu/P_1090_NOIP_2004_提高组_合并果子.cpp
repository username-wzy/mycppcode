#include<bits/stdc++.h>
#define int long long

using namespace std;

void read(int &x){ 
	int f=1;x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
}

void solve() {
    priority_queue<int, vector<int>, greater<int>> pq;
    int n;
    read(n);
    for (int i = 1; i <= n; i++) {
        int x;
        read(x);
        pq.push(x);
    }
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        cnt += a + b;
        pq.push(a + b);
    }
    cout << cnt;
}

signed main() {
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