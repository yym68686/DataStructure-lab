#include <stdio.h>
#define M 4
#define N 4
int A[M][N]={{9,7,6,8},{20,26,22,25},{28,36,25,30},{12,4,2,6}}, max[256], min[256];
void minMax(){
    for (int i = 0; i < M; i++){
        min[i] = A[i][0];
        for (int j = 0; j < N; j++)
            if (min[i] > A[i][j])
                min[i] = A[i][j];
    }
    for (int i = 0; i < M; i++){
        max[i] = A[0][i];
        for (int j = 0; j < N; j++)
            if (max[i] < A[j][i])
                max[i] = A[j][i];
    }
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            if (min[i] == max[j])
                printf("%d\n", A[i][j]);
}
int main(){
    minMax();
}