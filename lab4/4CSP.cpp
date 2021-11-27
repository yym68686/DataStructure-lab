#include <stdio.h>
int n, k, viste[22], num, summ = 0;
int main(){
    freopen("4CSP", "r", stdin);
    scanf("%d", &n);
    while (scanf("%d", &k) != EOF)
    for (int j = 0; j < 20; j++)
        if (5 - viste[j] >= k){
            for (int kk = 1; kk <= k; kk++)
                printf("%d ", 5 * j + kk + viste[j]);
            puts("");
            viste[j] = k;
            break;
        }
}