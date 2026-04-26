#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, l;
    cin >> n >> l;
    for (int i = 1;; i++) {
        int sum = 0;
        int j = i * 2;
        bool flag = false;
        for (int k = n; k >= 1; k--) {
            sum = j + j / 2 + l;
            j = sum;
            if (k == 1) {
                break;
            }
            if (sum % 2 != 0) {
                flag = 1;
                break;
            }
        }
        if (!flag) {
            cout << sum;
            break;
        }
    }
    return 0;
}