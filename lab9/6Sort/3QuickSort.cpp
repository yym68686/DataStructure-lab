#include <stdio.h>
#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;
int n, b[35000];
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
int main(){
	int a = 32700;
	while (a) b[n++] = a--;
    fstream ReadFile("1Sample");

    for (int i = 0; i < n; i++)
        ReadFile << b[i] << endl;
    ReadFile.close();
    quickSort(b, 0, n - 1000 );
    for (int i = 0; i < 10; i++)
        printf("%d ", b[i]);
}