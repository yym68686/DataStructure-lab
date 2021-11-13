#include <stdio.h>
#include <algorithm>
int n, l, t, a[999], num, speed[999], use[999];
int main(){
    freopen("5CSP1", "r", stdin);
    scanf("%d%d%d", &n, &l, &t);
    while (scanf("%d", &a[num]) != EOF) num++;
    std::fill(speed, speed + 999, 1);
    while(t--){
        std::fill(use, use + 999, -1);
        for (int j = 0; j < n; j++){
            a[j] += speed[j];
            if (a[j] == l || a[j] == 0) speed[j] *= -1;
            if(use[a[j]] >= 0) speed[j] *= -1, speed[use[a[j]]] *= -1;
            else use[a[j]] = j;
        }
    }
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}