#include <stdio.h>
int n, a[1111], num, maxx = 0, ans = 0;
int count(int a[]){
    int flag = 0, num = a[0] == 0 ? -1 : 0;
    for(int i = 0; i < n; i++){
        if (a[i] == 0 && flag == 0) flag = 1;
        else if (flag == 1 && a[i]) flag = 0, num++;
    }
    return num + 1;
}
int main(){
    freopen("4CSP1", "r", stdin);
    scanf("%d", &n);
    while (scanf("%d", &a[num++]) != EOF);
    for (int i = 0; i < n; i++) maxx = a[i] > maxx ? a[i] : maxx;
    for (int i = 0; i < maxx + 2; i++){
        for (int j= 0; j < n; j++)
            a[j] = a[j] < i ? 0 : a[j];
        ans = count(a) > ans ? count(a) : ans;
    }
    printf("%d", ans);
}