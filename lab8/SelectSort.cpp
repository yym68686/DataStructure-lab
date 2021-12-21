#include <stdio.h>
int x[] = {62, 58, 88, 47, 73, 99, 35, 51, 93, 29, 37, 49, 56, 36, 48, 50};
int main(){
    int size = sizeof(x) / sizeof(x[0]);
    for (int i = 0; i < size; i++)
        printf("%d ", x[i]);
    for(int i = 0; i < size; i++){
        int minn = 0x3f3f3f3f, index;
        for (int j = i; j < size; j++)
            if (x[j] < minn) {
                index = j;
                minn = x[j];
            }
        x[index] = x[i];
        x[i] = minn;
    }
    puts("");
    for (int i = 0; i < size; i++)
        printf("%d ", x[i]);
}