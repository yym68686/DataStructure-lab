#include <stdio.h>
long long n, a[] = {62, 58, 88, 47, 73, 99, 35, 51, 93, 29, 37, 49, 56, 36, 48, 50};
long long b[111111], sum = 0;
void mergesort(long long a[], long long s, long long mid, long long e, long long b[])
{
    long long i = s, j = mid+1, q = s, m = mid;
    while (i <= m && j <= e)
    {
        if (a[i] < a[j])
            b[q++] = a[i++];
        else
            b[q++] = a[j++];
    }
    while (i <= m)
        b[q++] = a[i++];
    while (j <= e)
        b[q++] = a[j++];
    for (int i = s; i <= e;a[i]=b[i],i++)
        ;
}
void merge(long long a[], long long s, long long e, long long b[])
{
    if (s < e)
    {
        long long mid = s + (e - s) / 2;
        merge(a, s, mid, b);
        merge(a, mid + 1, e, b);
        mergesort(a, s, mid, e, b);
    }
}
int main()
{
    n = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < n; i++)
        printf("%lld ", a[i]);
    merge(a, 0, n - 1, b);
    puts("");
    for (int i = 0; i < n; i++)
        printf("%lld ", b[i]);
}