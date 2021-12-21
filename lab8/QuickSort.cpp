#include <stdio.h>
int x[] = {62, 58, 88, 47, 73, 99, 35, 51, 93, 29, 37, 49, 56, 36, 48, 50};
void quickSort(int num[], int left, int right) {
    if (num == NULL || left >= right) return;
    int i = left;
    int j = right;
    int temp = num[i];
    while (i < j) {
        while (i < j && num[j] >= temp) j--;
        num[i] = num[j];
        while (i < j && num[i] <= temp) i++;
        num[j] = num[i];
        num[i] = temp;
    }
    quickSort(num, left, i - 1);
    quickSort(num, i + 1, right);
}
int main(){
    int size = sizeof(x) / sizeof(x[0]);
    for (int i = 0; i < size; i++)
        printf("%d ", x[i]);
    quickSort(x, 0, size);
    puts("");
    for (int i = 0; i < size; i++)
        printf("%d ", x[i]);
}