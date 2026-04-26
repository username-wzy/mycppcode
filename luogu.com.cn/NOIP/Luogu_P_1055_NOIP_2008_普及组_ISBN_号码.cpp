#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    string isbn;
    cin >> isbn;
    int sum = 0, k = 1;
    for (int i = 0; i < isbn.size() - 1; i++) {
        if (isdigit(isbn[i])) {
            sum += (isbn[i] - '0') * k++;
        }
    }
    sum %= 11;
    if (sum + '0' == isbn[isbn.size() - 1] || (sum == 10 && isbn[isbn.size() - 1] == 'X')) {
        cout << "Right";
    } else {
        if (sum == 10) {
            isbn[isbn.size() - 1] = 'X';
            cout << isbn;
        } else {
            isbn[isbn.size() - 1] = sum  + '0';
            cout << isbn;
        }
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