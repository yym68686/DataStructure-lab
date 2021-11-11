#include <stdio.h>
int n, a[2222], b[2222], c[2222], d[2222], num = -1, numm = -1, maxx = 0, sum, time[1111111] = {0};
int main(){
    freopen("5CSP1", "r", stdin);
    scanf("%d", &n);
    while (++num != n) scanf("%d%d", &a[num], &b[num]);
    while (++numm != n) scanf("%d%d", &c[numm], &d[numm]);
    for (int i = 0; i < n; i++) {
        for (int j = a[i] + 1; j <= b[i]; j++) time[j]++, maxx = j > maxx ? j : maxx;
        for (int j = c[i] + 1; j <= d[i]; j++) time[j]++, maxx = j > maxx ? j : maxx;
    }
    for (int i = 0; i <= maxx; i++) sum = time[i] == 2 ? sum + 1 : sum;
    printf("%d", sum);
}