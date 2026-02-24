
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

constexpr int N = 2e5 + 5;

ll n, a[N], b[N], cnt = 0;

void mergeSort(int l, int r)
{
    if (l < r) {
        int mid = (l + r) / 2;
        mergeSort(l, mid);
        mergeSort(mid + 1, r);
        int i = l, j = mid + 1, t = l;
        while (i <= mid && j <= r) {
            if (a[i] <= a[j])
                b[t++] = a[i++];
            else
                b[t++] = a[j++], cnt += (mid - i + 1);
        }
        while (i <= mid)
            b[t++] = a[i++];
        while (j <= r)
            b[t++] = a[j++];
        for (int s = l; s <= r; s++)
            a[s] = b[s];
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    mergeSort(0, n - 1);
    cout << cnt << '\n';
    return 0;
}