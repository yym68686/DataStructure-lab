#include <stdio.h>
int n, m, l, a[255555], num, h[333];
int main(){
    freopen("4CSP2", "r", stdin);
    scanf("%d%d%d", &n, &m, &l);
    while (scanf("%d", &a[num]) != EOF) num++;
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
        h[a[i * m + j]]++;
    for (int i = 0; i < l; i++)
        printf("%d ", h[i]);
}