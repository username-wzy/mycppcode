#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    char alphabet[26];
    for (int i = 0; i < 26; i++)
        alphabet[i] = i + 'A';
    for (int i = 0; i < 26; i++) {
        cout << alphabet[(i + n) % 26];
    }
    return 0;
}