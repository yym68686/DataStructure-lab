#include <stdio.h>
int n, k[111111], t[111111], num, state[4], tran[4] = {0, 3, 1, 2}, summ = 0;
void change(int time, int &sta, int &curtime){
    if (!sta) return;
    int nexttime = time - curtime;
    if (time >= curtime){
        sta = tran[sta];
        curtime = state[sta] - nexttime;
    }
    else
        curtime -= time;
}
int main(){
    freopen("3CSP", "r", stdin);
    scanf("%d%d%d", &state[1], &state[2], &state[3]);
    scanf("%d", &n);
    while (scanf("%d%d", &k[num], &t[num]) != EOF) num++;
    for (int i = 0; i < n; i++)
        if (k[i] != 3 && k[i] != 2){
            summ += t[i];
            for (int j = i + 1; j < n; j++)
                change(t[i], k[j], t[j]);
        }
    printf("%d\n", summ);
}