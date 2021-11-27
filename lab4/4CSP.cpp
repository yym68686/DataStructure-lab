#include <stdio.h>
int n, k[111], viste[22], num, summ = 0;
int main(){
    freopen("4CSP", "r", stdin);
    scanf("%d", &n);
    while (scanf("%d", &k[num]) != EOF) num++;
    for (int i = 0; i < num; i++)
    for (int j = 0; j < 20; j++)
        if (5 - viste[j] >= k[i]){
            for (int kk = 1; kk <= k[i]; kk++)
                printf("%d ", 5 * j + kk + viste[j]);
            puts("");
            viste[j] = k[i];
            break;
        }
}