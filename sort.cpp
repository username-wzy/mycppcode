#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int mp[500];

bool cmp(char a, char b)
{
    return mp[a] < mp[b];
}

int cnt[10000005];
char a[10000005];

char buf[1 << 20], *p1 = buf, *p2 = buf;
#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin), p1 == p2) ? EOF : *p1++)

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    scanf("%s", a);
    char c = gc();
    while (c != EOF) {
        if (c >= 'a' && c <= 'z')
            cnt[c]++;
        c = gc();
    }

    const int n = strlen(a);

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= cnt[a[i]]; j++) {
            cout << a[i];
        }
    }

    return 0;
}
