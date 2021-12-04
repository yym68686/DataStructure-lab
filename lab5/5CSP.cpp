#include <stdio.h>
int n, L, r, t, A[666][666], num;
float sum;
int main(){
    freopen("5CSP1", "r", stdin);
    scanf("%d%d%d%d", &n, &L, &r, &t);
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
        scanf("%d", &A[i][j]);
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++){
        int x1 = i - r > 0 ? i - r : 0;
        int x2 = i + r < n ? i + r : n - 1;
        int y1 = j - r > 0 ? j - r : 0;
        int y2 = j + r < n ? j + r : n - 1;
        sum = 0;
        for (int k = x1; k <= x2; k++)
            for (int kk = y1; kk <= y2; kk++)
                sum += A[k][kk];
        sum /= (x2 - x1 + 1) * (y2 - y1 + 1) * 1.0;
        if (sum <= t) num++;
    }
    printf("%d", num);
}