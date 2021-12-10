#include <stdio.h>
int A[22][11], B[5][5], n, max = 0, map[44], xmin = 0x3f3f3f3f, ymin = 0x3f3f3f3f;
float sum;
int main(){
    freopen("5CSP", "r", stdin);
    for (int i = 0; i < 15; i++)
    for (int j = 0; j < 10; j++)
        scanf("%d", &A[i][j]);
    for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
        scanf("%d", &B[i][j]);
    scanf("%d", &n);

    int index = 0;
    for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
        if (B[i][j]) {
            map[index * 2] = i;
            map[index++ * 2 + 1] = j;
            xmin = xmin > i ? i : xmin;
            ymin = ymin > j ? j : ymin;
        }

    for (int i = 2; i < 15; i++){
        int flag = 0;
        for (int j = 0; j < index; j++){
            if (A[map[j * 2] + i - xmin - 1][map[j * 2 + 1] + n - ymin] || map[j * 2] + i - xmin - 1> 14) {
                printf("%d %d %d\n", A[map[j * 2] + i][map[j * 2 + 1] + n], map[j * 2] + i, map[j * 2 + 1] + n);
                flag = 1;
                break;
            }
        }
        if (flag) break;
        else max = i;
    }
    for (int i = 0; i < index; i++)
        A[map[i * 2] + max - xmin - 1][map[i * 2 + 1] + n - ymin] = 1;

    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 10; j++)
            printf("%d ", A[i][j]);
        puts("");
    }

}