#include <stdio.h>
#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;
int inde = 1, num[55555], n, arr[55555], w = 6;
clock_t starttime, endtime;
string temp;

void InsertSort(int a[], int n){
    for (int i = 1; i < n; i++){
        int k, tmp = a[i];
        for (k = i - 1; k >= 0; k--) if (a[k] < a[i]) break;
        for (int j = i - 1; j >= k + 1; j--) a[j + 1] = a[j];
        a[k + 1] = tmp;
    }
}

void BubbleSort(int a[], int n){
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n - i - 1; j++)
        if (a[j] > a[j + 1]){
            int temp = a[j];
            a[j] = a[j + 1];
            a[j + 1] = temp;
        }
}

void QuickSort(int num[], int left, int right) {
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
    QuickSort(num, left, i - 1);
    QuickSort(num, i + 1, right);
}

void SelectSort(int a[], int n){
    for(int i = 0; i < n; i++){
        int minn = 0x3f3f3f3f, index;
        for (int j = i; j < n; j++)
            if (a[j] < minn) {
                index = j;
                minn = a[j];
            }
        a[index] = a[i], a[i] = minn;
    }
}
int main(){
    while (inde != 11){
        n = 0;
        fstream ReadFile(to_string(inde) + "Sample");
        cout << setw(2) << to_string(inde++) << "Sample: ";
        while(getline(ReadFile, temp)) num[n++] = stoi(temp);
        ReadFile.close();

        for (int i = 0; i < n; i++) arr[i] = num[i];
        starttime = clock();
        InsertSort(arr, n);
        endtime = clock();
        cout << setw(w) << fixed << setprecision(3) << double(endtime - starttime) / CLOCKS_PER_SEC << "s";

        for (int i = 0; i < n; i++) arr[i] = num[i];
        starttime = clock();
        BubbleSort(arr, n);
        endtime = clock();
        cout << setw(w) << fixed << setprecision(3) << double(endtime - starttime) / CLOCKS_PER_SEC << "s";

        for (int i = 0; i < n; i++) arr[i] = num[i];
        starttime = clock();
        QuickSort(arr, 0, n);
        endtime = clock();
        cout << setw(w) << fixed << setprecision(3) << double(endtime - starttime) / CLOCKS_PER_SEC << "s";

        for (int i = 0; i < n; i++) arr[i] = num[i];
        starttime = clock();
        SelectSort(arr, n);
        endtime = clock();
        cout << setw(w) << fixed << setprecision(3) << double(endtime - starttime) / CLOCKS_PER_SEC << "s" << endl;


    }
    // ReadFile.open(to_string(inde) + "Sample");
    // for (int i = 0; i < n; i++)
    //     ReadFile << arr[i] << endl;
    // ReadFile.close();
}