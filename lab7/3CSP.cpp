#include <stdio.h>
int m, n, A, T, D, E, sum, state[999];
int main(){
    freopen("3CSP1", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &m);
        sum = 0;
        for (int j = 0; j < m; j++){
            scanf("%d", &A);
            if (A > 0){
                if (j != 0 && sum != A) D++, state[i]++;
                sum = A;
            }
            else sum += A;
        }
        T += sum;
    }
    for (int i = 0; i < n; i++)
        if (state[i] && state[(i + 1) % n] && state[(i + 2) % n]) E++;
    printf("%d %d %d", T, D, E);
}