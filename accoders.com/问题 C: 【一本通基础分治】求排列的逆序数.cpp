#include <iostream>

int a[100005], b[100005];
int cnt = 0;

void mergesort(int l, int r)
{
    if (l >= r)
        return;
    int mid = (l + r) >> 1;
    mergesort(l, mid);
    mergesort(mid + 1, r);
    int i = l, j = mid + 1, t = l;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j])
            b[t++] = a[i++];
        else
            b[t++] = a[j++], cnt += mid - i + 1;
    }
    while (i <= mid)
        b[t++] = a[i++];
    while (j <= r)
        b[t++] = a[j++];
    for (int s = l; s <= r; s++)
        a[s] = b[s];
}

int main()
{
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    mergesort(1, n);
    std::cout << cnt;
    return 0;
}