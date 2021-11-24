#include <stdio.h>
#include <algorithm>
typedef struct
{
    int i, j, v;
} Triple;
typedef struct
{
    Triple arr[256];
    int Rows, Cols, Nums;
} SqSMatrix;
bool cmp(Triple a, Triple b){
    return a.i < b.i;
}
void TransposeSMatrix(SqSMatrix &A, SqSMatrix &B){
    B.Rows = A.Cols;
    B.Cols = A.Rows;
    B.Nums = A.Nums;
    if (A.Nums > 0){
        int q = 0;
        for (int k = 0; k < A.Cols; k++){
            for (int p = 0; p < A.Nums; p++){
                if (A.arr[p].j == k){
                    B.arr[q].i = A.arr[p].j;
                    B.arr[q].j = A.arr[p].i;
                    B.arr[q].v = A.arr[p].v;
                    q++;
                }
            }
        }
    }
}
void FastTransposeSMatrix(SqSMatrix &A, SqSMatrix &B){
    int rowNum[256], rowStart[256];
    B.Rows = A.Cols;
    B.Cols = A.Rows;
    B.Nums = A.Nums;
    if (A.Nums > 0){
        int q = 0;
        for (int k = 0; k < A.Cols; k++) rowNum[k] = 0;
        for (int p = 0; p < A.Nums; p++) rowNum[A.arr[p].j]++;
        rowStart[0] = 0;
        for (int k = 0; k < A.Cols; k++) rowStart[k] = rowStart[k - 1] + rowNum[k - 1];
        for (int p = 0; p < A.Nums; p++){
            q = rowStart[A.arr[p].j];
            B.arr[q].i = A.arr[p].j;
            B.arr[q].j = A.arr[p].i;
            B.arr[q].v = A.arr[p].v;
            rowStart[A.arr[p].j]++;
        }
    }
}
int main(){
    SqSMatrix A, B;
    A.arr[0].i = 0;
    A.arr[0].j = 2;
    A.arr[0].v = 4;

    A.arr[1].i = 1;
    A.arr[1].j = 1;
    A.arr[1].v = 6;

    A.arr[2].i = 3;
    A.arr[2].j = 0;
    A.arr[2].v = 5;

    A.arr[3].i = 3;
    A.arr[3].j = 4;
    A.arr[3].v = 3;

    A.arr[4].i = 4;
    A.arr[4].j = 2;
    A.arr[4].v = 7;

    A.Cols = 5;
    A.Rows = 5;
    A.Nums = 5;

// 简单方法
    // for (int i = 0; i < 5; i++){
    //     printf("%d %d %d\n", A.arr[i].i, A.arr[i].j, A.arr[i].v);
    //     int temp = A.arr[i].i;
    //     A.arr[i].i = A.arr[i].j;
    //     A.arr[i].j = temp;
    // }
    // puts("");
    // std::sort(A.arr, A.arr + 5, cmp);
    // for (int i = 0; i < 5; i++){
    //     printf("%d %d %d\n", A.arr[i].i, A.arr[i].j, A.arr[i].v);
    // }


    for (int i = 0; i < 5; i++)
        printf("%d %d %d\n", A.arr[i].i, A.arr[i].j, A.arr[i].v);
    puts("");
    FastTransposeSMatrix(A, B); // 快速转置法
    // TransposeSMatrix(A, B); // 列序遍历法
    for (int i = 0; i < 5; i++)
        printf("%d %d %d\n", B.arr[i].i, B.arr[i].j, B.arr[i].v);

}
