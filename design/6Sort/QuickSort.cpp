#include <stdio.h>
// int x[] = {62, 58, 88, 47, 73, 99, 35, 51, 93, 29, 37, 49, 56, 36, 48, 50};
// int x[] = {5, 9, 8, 7, 6, 10, 4, 3, 2, 1};
int x[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
void quickSort(int num[], int left, int right) {
    if (num == NULL || left >= right) return;
    int i = left;
    int j = right;
    int key = num[i];
    while (i < j) {
        while (i < j && num[j] >= key)
            j--;
        num[i] = num[j];
        while (i < j && num[i] <= key)
            i++;
        num[j] = num[i];
    }
    num[i] = key;
    quickSort(num, left, i - 1);
    quickSort(num, i + 1, right);
}
void ShellSort(int a[], int n){
    int j;
    for (int gap = n >> 1; gap; gap >>= 1){
        for (int i = gap; i < n; i++){
            int temp = a[i];
            for (j = i - gap; j >= 0 && a[j] > temp; j -= gap) a[j + gap] = a[j];
            a[j + gap] = temp;
        }
    }
}

int main(){
    int size = sizeof(x) / sizeof(x[0]);
    for (int i = 0; i < size; i++)
        printf("%d ", x[i]);
    ShellSort(x, size);
    // quickSort(x, 0, size - 1);
    puts("");
    for (int i = 0; i < size; i++)
        printf("%d ", x[i]);
}