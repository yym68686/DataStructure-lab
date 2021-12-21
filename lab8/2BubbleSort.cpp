#include <stdio.h>
int x[] = {62, 58, 88, 47, 73, 99, 35, 51, 93, 29, 37, 49, 56, 36, 48, 50};
int main(){
    int size = sizeof(x) / sizeof(x[0]);
    for (int i = 0; i < size; i++)
        printf("%d ", x[i]);
    for(int i = 0; i < size; i++)
    for(int j = 0; j < size - i - 1; j++)
        if (x[j] > x[j + 1]){
            int temp = x[j];
            x[j] = x[j + 1];
            x[j + 1] = temp;
        }
    puts("");
    for (int i = 0; i < size; i++)
        printf("%d ", x[i]);
}